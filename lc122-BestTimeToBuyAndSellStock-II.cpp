#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, days = prices.size();
        for (int i = 1; i < days; ++i) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};