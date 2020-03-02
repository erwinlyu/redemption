#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())  return res;
        vector<string> temp;
        helper(s, temp, 0);
        return res;
    }
private:
    vector<vector<string>> res;
    void helper(string&s, vector<string>& temp, int start) {
        if (start >= s.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                helper(s, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string&s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};