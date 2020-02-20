#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /* dp solution
        dp[i][j] denotes the number of distinct subsequences of t[0~i-1] and s[0~j-1].
        at first I thought this was a backtracking problem, but duplicate issue
        is hard to handle.
        
        ref:https://leetcode.com/problems/distinct-subsequences/discuss/37327/Easy-to-understand-DP-in-Java
        https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space) */
    int numDistinct(string s, string t) {
        int rows = t.size(), cols = s.size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 0; i <= cols; ++i)  dp[0][i] = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dp[i + 1][j + 1] = dp[i + 1][j] + (t[i] == s[j] ? dp[i][j] : 0);
            }
        }
        return dp[rows][cols];
    }
};