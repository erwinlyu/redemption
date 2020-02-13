#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /* bottom-up dp solution
        ref:https://leetcode.com/problems/triangle/discuss/38730/DP-Solution-for-Triangle
        very neat and clever solution. top-down would be hard. */
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())    return 0;
        int n = triangle.size();
        vector<int> minSum = triangle.back();   // initialize memo with the last row.
        for (int layer = n - 2; layer >= 0; --layer) {  // for each layer above the bottom.
            for (int i = 0; i <= layer; ++i) {
                // find the lesser node of i's two children, add itself.
                minSum[i] = min(minSum[i], minSum[i + 1]) + triangle[layer][i];
            }
        }
        return minSum[0];
    }
};