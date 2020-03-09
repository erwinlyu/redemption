#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    // first thought: backtracking. but that does not work out.
    // would meet Time Limit Exceeded error in case like:
    // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab" ["a", "aa","aaa",...]
    // in extreme cases like this, time complexity can be as terrible as brute force, ~O(2^n).

    // dp is the right solution.
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (string word : wordDict) {
                if (word.size() <= i) {
                    if (dp[i - word.size()]) {
                        if (s.substr(i - word.size(), word.size()) == word) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp.back();
    }
};