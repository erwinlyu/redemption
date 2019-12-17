#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // the original version:
    bool canJump(vector<int>& nums) {
        if(nums.empty())    return false;
        int nLen = nums.size();
        vector<int> dp(nLen);
        dp[0] = nums[0];
        for(int pos = 1; pos < nLen; ++pos){
            if(pos > dp[pos - 1])   return false;
            if(pos < dp[pos - 1] && pos + nums[pos] <= dp[pos - 1])
                dp[pos] = dp[pos - 1];
            else    dp[pos] = pos + nums[pos];
            if(dp[pos] >= nLen - 1) return true;
        }
        return true;    //  should not return false. consider case {0}.
    }

    // the improved version:
    // GREEDY approach
    // as we only care about the farthest element that can be reached when start from nums[0]
    // before we reach the last element,
    // there is no need to maintain the array, dp[], which stores
    // the changing of farthest-reachable range.
    // that is to say, we only care about the FINAL farthest-reachable element for this specific nums.
    // so instead of maintaining dp[], defining a variable 'farthest' can reduce space complexity
    // from O(n) to O(1).
    bool canJump(vector<int>& nums){
        int nLen = nums.size();
        int farthest = nums[0];
        for(int i = 1; i < nLen; ++i){
            if(i > farthest)  return false;
            farthest = max(farthest, i + nums[i]);
            if(farthest >= nLen - 1)    return true;
        }
        return true;
    }
};
int main(){
    vector<int> input = {2,5,0,0};
    Solution sln;
    if(sln.canJump(input))  cout << "can" << endl;
    return 0;
}