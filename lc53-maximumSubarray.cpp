#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

/* // the 0ms submission on leetcode
    // about accelerating c++ I/O with the codes below, refer to:
    // https://www.hankcs.com/program/cpp/cin-tie-with-sync_with_stdio-acceleration-input-and-output.html
    // https://blog.csdn.net/qq_33248299/article/details/52144485
    static const auto speedup = []() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp=0,result=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            temp=(temp<0?nums[i]:temp+nums[i]);
            result=max(temp,result);
        }
        return result;
    }
}; */

// a clearer dp solution. https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts
// state transition equation should be:
// maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]
// actually the 0ms submission above obeys this pattern as well.
// maintaining dp[] is not necessary for this problem because it only requires the finally max sum.


// my own rubbish dynamic programming solution, VERY slow...QAQ
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nLen = nums.size();
        vector<int> dp(nLen);
        dp[0] = nums[0];
        int maxpos = 0;
        for(int i = 1; i < nLen; ++i){
            int intervalSum = dp[maxpos];
            for(int j = maxpos + 1; j <= i; ++j){
                // here, the reason of modifying intervalSum to 0 when it is less than 0
                // is that when the sum of some numbers is already below 0,
                // the sum of the numbers behind these numbers is certainly greater than this sum.
                // a representative case is: {8,-19,2,3,-4,20}
                if(intervalSum < 0) intervalSum = 0;
                intervalSum += nums[j];
            }
            if(nums[i] >= intervalSum){
                if(nums[i] >= dp[maxpos]){
                    dp[i] = nums[i];
                    maxpos = i;
                }
                else    dp[i] = dp[maxpos];
            }
            else{
                if(intervalSum >= dp[maxpos]){
                    dp[i] = intervalSum;
                    maxpos = i;
                }
                else    dp[i] = dp[maxpos];
            }
        }
        return dp[maxpos];
    }
};
int main(){
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    vector<int> input = {8,-19,2,3,-4,20}; //{-2,1,-3,4,-1,2,1,-5,4}, {1,2}, {-1,-2}, {8,-19,5,-4,20}
    Solution sln;
    cout << sln.maxSubArray(input) << endl;
    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    cout << "time = " << time << "s" << endl;
    return 0;
}