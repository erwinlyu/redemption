#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // method 1: 偏数学的做法.
    // 思想是n被分为k份，这k份越平均它们的乘积越大
    int cuttingRope(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++i) {  // 分成i段
            int product = 1, res_len = n;
            for (int j = i; j >= 1; --j) {  // 尽可能将剩余长度分为均匀的j段
                product *= res_len / j;
                res_len -= res_len / j;
            }
            if (res < product)  res = product;
            else    break;
        }
        return res;
    }

    // method 2: 简单bottom-up dp, 状态转移方程是dp[i] = max{dp[i], j*(i-j), j*dp[i-j]}
    // O(n^2) time, O(n) space
    int dp(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }

    // method 3: optimized dp.
    // 思路是:所有大于3的数字均可拆成1,2,3之和,且对3的余数只能是0,1,2. 因此用dp[0],dp[1],dp[2]
    //       表示所有大于3的值. 这样空间可以降至O(1).
    int optimized_dp(int n) {
        vector<int> dp = {0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            dp[i % 3] = max(max(dp[i - 1], i - 1),
                            max(2 * max(dp[(i - 2) % 3], i - 2),
                                3 * max(dp[(i - 3) % 3], i - 3)));
        }
        return dp[n % 3];
    }
};