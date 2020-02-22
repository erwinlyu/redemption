#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    // 错误思路：将近prices的每一段局部最大值记录下来，然后排序，取最大的两个求和。打脸例子：[1,2,4,2,5,7,2,4,9,0]
    
    int maxProfit(vector<int>& prices) {
        // 正确思路1：线性扫描. time O(n), space O(n).
        // 以第二笔交易的买入日i为分界.
        // 第一次扫描为从前向后，搜索第一笔交易(0到第i天内)可以获得的最大利润，保存在memo里.
        // 第二次扫描为从后向前，搜索第二笔交易(i到第n-1天)可以获得的最大利润. 第二笔的最大利润与
        //  memo[i]相加可以求得两笔交易利润之和profit，并与先前的profit作max().
        // ref:https://zhuanlan.zhihu.com/p/53849130
        if (prices.size() < 2)  return 0;
        int p_len = prices.size(), min_price = prices[0], max_price = prices[p_len - 1];
        vector<int> memo(p_len, 0);
        for (int i = 1; i < p_len; ++i) {
            min_price = min(min_price, prices[i]);
            memo[i] = max(memo[i - 1], prices[i] - min_price);
        }
        int profit = 0;
        for (int i = p_len - 1; i > 0; --i) {

            // 注：此处与max_price-prices[i]求和的是memo[i]，而不是memo[i-1]，
            // 因为第i天是可以作为第一笔交易的卖出日的.
            profit = max(profit, memo[i] + max_price - prices[i]);
            max_price = max(max_price, prices[i]);
        }
        return profit;

        // 正确思路2：dp. 可拓展至k笔交易.
        // ref:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
        // 状态转移方程: dp[k][i] = max(dp[k][i-1], dp[k-1][j]+prices[i]-prices[j]) 其中j=[0,..,i-1].
        // 方程中k指第k笔交易，i指第i个交易日,dp[k][i]保存前i天，包括第i天，k笔交易获得的最大利润.
        // 如果第i个交易日没有交易，那么dp[k][i] = dp[k][i-1];
        // 如果第i个交易日完成了一笔交易，即第i天卖出了第j(j<=i-1)天买入的股票，那么dp[k][i] = dp[k-1][j]+(prices[i]-prices[j])

        // method 2.1: 状态转移方程的直接实现。时间复杂度O(k*n^2) 空间复杂度O(k*n).
        // 这种做法超时.
        if (prices.size() < 2)  return 0;
        int p_len = prices.size(), transactions = 2;
        vector<vector<int>> dp(transactions + 1, vector<int>(p_len, 0));
        for (int k = 1; k < transactions + 1; ++k) {    // 0笔交易那一行全部为0， 所以k从1开始
            for (int i = 1; i < p_len; ++i) {
                int min_p = prices[0];
                for (int j = 1; j < i; ++j) {
                    min_p = min(min_p, prices[j] - dp[k - 1][j]);
                }
                dp[k][i] = max(dp[k][i - 1], prices[i] - min_p);
            }
        }
        return dp[transactions][p_len - 1];

        // method 2.2: 避免了2.1中的重复计算min_p. 时间/空间复杂度O(k*n).
        // 为什么2.1中min_p是重复计算的？
        // 因为min_P保存了序列[0,..,i]中prices[j]-dp[k-1][j]的最小值，而在变量i的上一次循环中，
        // 范围为[0,...,i-1]的min_p已经计算过了，所以只需要考察新的case，即i，所需要更新的min_p.
        if (prices.size() < 2)  return 0;
        int p_len = prices.size(), transactions = 2;
        vector<vector<int>> dp(transactions + 1, vector<int>(p_len, 0));
        for (int k = 1; k < transactions + 1; ++k) {
            int min_p = prices[0];
            for (int i = 1; i < p_len; ++i) {
                min_p = min(min_p, prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - min_p);
            }
        }
        return dp[transactions][p_len - 1];
    }
};