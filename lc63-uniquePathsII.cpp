#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // method 1: use obstacleGrid[][] as dp memo[][].
        // though this method's space complexity is O(1), original input would be changed.
        if (obstacleGrid[0][0] == 1)    return 0;
        obstacleGrid[0][0] = 1;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for (int i = 1; i < m; ++i)
            obstacleGrid[i][0] = (obstacleGrid[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0;
        for (int i = 1; i < n; ++i)
            obstacleGrid[0][i] = (obstacleGrid[0][i - 1] == 1 && obstacleGrid[0][i] == 0) ? 1 : 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[m - 1][n - 1];

    // method 2: set up an independent dp memo[].
    // reference:https://leetcode.com/problems/unique-paths-ii/discuss/23252/4ms-O(n)-DP-Solution-in-C%2B%2B-with-Explanations
    if (obstacleGrid[0][0] == 1)    return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<long> dp(m, 0);  //some case's correct answer could be greater than INT_MAX
    for (int i = 0; i < m; ++i) {
        if (!obstacleGrid[i][0])    dp[i] = 1;
        else    break;
    }
    for(int i = 1; i < n; ++i) {
        bool accessible = false;
        if (obstacleGrid[0][i]) dp[0] = 0;
        else    accessible = true;
        for (int j = 1; j < m; ++j) {
            if (!obstacleGrid[j][i]) {
                dp[j] += dp[j - 1];
                if (dp[j])  accessible = true;
            }
            else    dp[j] = 0;
        }
        if (!accessible)    return 0;
    }
    return dp[m - 1];
    }
};

int main(){
    vector<vector<int>> input = {{1}};
    Solution sln;
    printf("\n%d", sln.uniquePathsWithObstacles(input));
    return 0;
}