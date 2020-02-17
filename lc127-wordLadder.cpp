#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    //ref: https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
    //ref: solution page of this problem.


    /* method 1: begin to end graph BFS. */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // dict works the unvisited array of wordList. Once a word is used, it will be removed from dict.
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())   return 0;
        int wordSize = beginWord.size(), listLen = wordList.size(), res = 1;

        // generic_map is an unordered_map that stores generic form for each word.
        // generic forms are keys, words are values.
        // e.g. "hit"'s generic forms are "*it", "h*t", "hi*".
        unordered_map<string, vector<string>> generic_map;
        for (int i = 0; i < listLen; ++i) {
            for (int j = 0; j < wordSize; ++j) {
                string temp = wordList[i];
                temp[j] = '*';
                generic_map[temp].push_back(wordList[i]);
            }
        }

        queue<string> todo; // use queue to store nodes of current level.
        todo.push(beginWord);
        while (!todo.empty()) {
            int qSize = todo.size();
            for (int i = 0; i < qSize; ++i) {
                string curWord = todo.front();
                todo.pop();
                dict.erase(curWord);    // when a word is visited, remove it from dict.
                if (curWord == endWord) return res;
                for (int j = 0; j < wordSize; ++j) {
                    char c = curWord[j];
                    curWord[j] = '*';
                    for (string s : generic_map[curWord]) {
                        if (dict.find(s) != dict.end()) todo.push(s);
                    }
                    curWord[j] = c;
                }
            }
            res++;
        }
        return 0;
    }

    /* method 2: bidirectional graph BFS. 
        the difference from method 1 is that the BFS start from begin and end word, respectively.
        use unordered_set to store current-level nodes of both BFS instead of queue.
        each round, the BFS with less current-level nodes runs.
        use 2 pointers to exchange the BFS to run. 
        
        because of the exponentially grow of # of nodes in each level, bidirectional
        BFS significantly reduce the scale of the graph.
        so method 2 runs MUCH FASTER than method 1 (28ms vs. 400+ms) */
    int bidirectional_bfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), begin2end, end2begin, *pThis, *pThat;
        if (dict.find(endWord) == dict.end())   return 0;
        int res = 2;
        begin2end.insert(beginWord);
        end2begin.insert(endWord);
        while (!begin2end.empty() && ! end2begin.empty()) {
            if (begin2end.size() < end2begin.size()) {  // find the BFS with less current-level nodes.
                pThis = &begin2end;
                pThat = &end2begin;
            }
            else {
                pThis = &end2begin;
                pThat = &begin2end;
            }

            unordered_set<string> temp; // to store nodes of next level temporarily.
            for (auto it = pThis->begin(); it != pThis->end(); ++it) {
                string word = *it;
                for (int i = 0; i < word.size(); ++i) {
                    char c = word[i];

                    // here, traverse 26 letters instead of using generic_map which used in method1,
                    // because otherwise program runs much slower, don't know why...
                    for (int j = 0; j < 26; ++j) {
                        word[i] = 'a' + j;
                        if (pThat->find(word) != pThat->end())  return res;
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }
            res++;

            // redesignate pThis with temp.
            pThis->swap(temp);
        }
        return 0;
    }
};