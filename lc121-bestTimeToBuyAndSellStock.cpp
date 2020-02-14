#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // method 1: my own dp solution, not concise. O(n)
    int maxProfit(vector<int>& prices) {
        int pLen = prices.size();
        int buyPrice, lowestPrice, maxPrft = 0;
        int day = 0;
        while (day < pLen - 1) {
            if (prices[day] < prices[day + 1]) {
                buyPrice = lowestPrice = prices[day];
                maxPrft = prices[day + 1] - prices[day];
                break;
            }
            day++;
        }
        day++;
        for (; day < pLen; ++day) {
            lowestPrice = min(lowestPrice, prices[day]);
            maxPrft = max(maxPrft, prices[day] - buyPrice);
            if (prices[day] - lowestPrice > maxPrft) {
                if (lowestPrice < buyPrice) buyPrice = lowestPrice;
                maxPrft = prices[day] - buyPrice;
            }
        }
        return maxPrft;
    }

    // method 2: much more concise dp code than method 1, 
    // same idea and same performance though.
    int method_2(vector<int>& prices) {
        int lowest = INT_MAX, profit = 0;
        for (int price : prices) {
            lowest = min(lowest, price);
            profit = max(profit, price - lowest);
        }
        return profit;
    }

    // method 3: Kadane's algorithm.
    // a dp algorithm, to solve "maximum subarray sum" problem.
    // transition equation: dp[i] = max(0, arr[i] - arr[i-1]) + arr[i] for i in [1, n-1]
    // also a O(n) algorithm but faster than method 1 & 2. (4ms vs. 8ms).
    // ref:https://hackernoon.com/kadanes-algorithm-explained-50316f4fd8a6
    int kadanes_algorithm(vector<int>& prices) {
        int cur = 0, maxSoFar = 0, days = prices.size();
        for (int day = 1; day < days; ++day) {
            cur = max(0, cur += prices[day] - prices[day - 1]);
            maxSoFar = max(cur, maxSoFar);
        }
        return maxSoFar;
    }
};