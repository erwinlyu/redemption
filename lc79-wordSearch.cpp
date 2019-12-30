#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())    return false;
        if(board.empty() || board[0].empty())   return false;
        m = board.size();
        n = board[0].size();
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(dfs(board, word, row, col, 0))    return true;
            }
        }
        return false;
    }
private:
    int m, n;
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int idx){
        if(row < 0 || row >= m || col < 0 || col >= n || word[idx] != board[row][col])
            return false;
        if(idx == word.size() - 1)  return true;    // found the last char of the string.
        char curr = board[row][col];

        // interesting method to avoid introducing 'visited[][]' array.
        // temporarily overwrite the element that has been transversed as '*'
        // so that it won't be picked up again. After the transversion, 
        // re-write it back.
        // however this consumes more memory than using 'visited[][]'array...
        board[row][col] = '*';
        bool hasNext = (dfs(board, word, row - 1, col, idx + 1)
                        || dfs(board, word, row + 1, col, idx + 1)
                        || dfs(board, word, row, col - 1, idx + 1)
                        || dfs(board, word, row, col + 1, idx + 1));
        board[row][col] = curr;
        return hasNext;
    }
};
int main(){
    vector<vector<char>> board = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
    string str = "abcced";
    Solution sln;
    if(sln.exist(board, str))   cout << "good";
    else    cout << "no good";
    return 0;
}