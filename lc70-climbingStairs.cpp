#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        return dp(n);
    }

private:
    // recursive method, easy to code but apt to meet Time Limit Exceeded error (e.g. n=44).
    int backtracking(int n){
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        return backtracking(n - 1) + backtracking(n - 2);
    }

    // DP method. Faster & memo-saving. 
    int dp(int n){
        int prev = 1, curr = 2;
        if(n < 3)   return n == 1 ? prev : curr;
        for(int i = 2; i < n; ++i){
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
int main(){
    int input = 44;
    Solution sln;
    cout << sln.climbStairs(input);
    return 0;
}