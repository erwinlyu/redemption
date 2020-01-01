#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i / 2; ++j)
                dp[i] += 2 * dp[j - 1] * dp[i - j];
            dp[i] += i % 2 == 0 ? 0 : dp[i / 2] * dp[i / 2];
        }
        return dp[n];
    }
};