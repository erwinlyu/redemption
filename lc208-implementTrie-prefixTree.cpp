#include <vector>
using namespace std;
class Trie {
private:
    bool is_end = false;
    vector<Trie*> next;
public:
    /** Initialize your data structure here. */
    Trie() {
        is_end = false;
        next = vector<Trie*>(26, NULL);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (auto c : word) {
            if (!node->next[c - 'a'])   node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (auto c : word) {
            if (!node->next[c - 'a'])   return false;
            node = node->next[c - 'a'];
        }
        return node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto c : prefix) {
            if (!node->next[c - 'a'])   return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */