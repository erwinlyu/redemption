#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* reference:https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP
    dp[i][j] means the minimum operations to convert word1[0,...,i) to word2[0,...,j)
    if word1[i] == word2[j], the State transition equation is dp[i][j] = dp[i-1][j-1];
    if word1[i] != word2[j], there would be 3 different cases:
        1) word1[i] needs to be replace by word2[j], dp[i][j] = dp[i-1][j-1]+1;
        2) word1[0,...,i-1) == word2[0,...,j), so word1[i] needs to be deleted, dp[i][j] = dp[i-1][j]+1;
        3) word1[0,..,i) + word2[j] == word2[0,..,j), so word1[i] needs to add a letter, dp[i][j] = dp[i][j-1]+1; */
class Solution {
public:
    int minDistance(string word1, string word2) {
        return dp_1D(word1, word2);
    }
private:
    int dp_2D(string word1, string word2) {
        int wLen1 = word1.size(), wLen2 = word2.size();
        vector<vector<int>> dp(wLen1 + 1, vector<int>(wLen2 + 1, 0));
        for (int i = 1; i <= wLen1; ++i)    dp[i][0] = i;
        for (int i = 1; i <= wLen2; ++i)    dp[0][i] = i;
        for (int i = 1; i <= wLen1; ++i) {
            for (int j = 1; j <= wLen2; ++j) {
                if (word1[i - 1] == word2[j - 1])   dp[i][j] = dp[i - 1][j - 1];
                else    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[wLen1][wLen2];
    }

    // the 2D dp matrix can be pruned into a vector
    int dp_1D(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= m; ++i)    dp[i] = i;
        for (int i = 1; i <= n; ++i) {
            pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= m; j++) {
                int temp = dp[j];
                if (word2[i - 1] == word1[j - 1])   dp[j] = pre;
                else dp[j] = min(pre, min(dp[j], dp[j - 1])) + 1;
                pre = temp;
            }
        }
        return dp[m];
    }
};