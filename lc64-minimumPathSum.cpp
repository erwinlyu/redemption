#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

    // maintain a 2-D array to store the minPathSum for each corresponding element.
    // space complexity O(n^2).
        vector<vector<int>> res(m, vector<int>(n, 0));
        res[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i) res[0][i] = grid[0][i] + res[0][i - 1];
        for(int i = 1; i < m; ++i)    res[i][0] = grid[i][0] + res[i - 1][0];
        for(int r = 1; r < m; ++r){
            for(int c = 1; c < n; ++c)
                res[r][c] = min(res[r - 1][c], res[r][c - 1]) + grid[r][c];
        }
        //return res[m - 1][n - 1];

    // maintain a 1-D col vector to store the minPathSum for current col until meet the last col.
    // space complexity O(n)
        vector<int> ret(m, 0);
        ret[0] = grid[0][0];
        for(int i = 1; i < m; ++i)  ret[i] = grid[i][0] + ret[i - 1];
        for(int i = 1; i < n; ++i){
            ret[0] += grid[0][i];
            for(int j = 1; j < m; ++j){
                ret[j] = min(ret[j], ret[j - 1]) + grid[j][i];
            }
        }
        return ret[m - 1];
    }
};
int main(){
    vector<vector<int>> input = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sln;
    cout << sln.minPathSum(input);
    return 0;
}