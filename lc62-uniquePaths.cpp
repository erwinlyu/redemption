#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // trivial recursion method:
        // " return uniquePaths(m - 1, n) + uniquePaths(m, n - 1); "
        // would meet Time Limit Exceeded error when
        // m and n are big, say, m=51, n = 9. So it's off the table.

        vector<vector<int>> memo(m, vector<int>(n, 0));
        memo[0][0] = 1;
        // return backtracking(m - 1, n - 1, memo);
        // return nonRecursion(m, n);
    }
private:
    int backtrack(int m, int n, vector<vector<int>>& memo){
        if(m == 0 && n != 0)    return backtrack(0, n - 1, memo);
        if(n == 0 && m != 0)   return backtrack(m - 1, 0, memo);
        if(memo[m][n] == 0){
            memo[m][n] = backtrack(m - 1, n, memo) + backtrack(m, n - 1, memo);
        }
        return memo[m][n];
    }

    int nonRecursion(int m, int n){
        // reference: the least memory-consuming submission on leetcode
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; ++i) memo[i][0] = 0;
        for(int i = 0; i <= n; ++i) memo[0][i] = 0;
        memo[0][1] = 1;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j)  memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
        }
        return memo[m][n];
    }
};
int main(){
    Solution sln;
    cout << sln.uniquePaths(7,3);
    return 0;
}