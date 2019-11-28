#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {   // pretty good time & space performance
        if(nums.empty())    return 0;
        int cnt = 0;
        int vLen = nums.size();
        for(int i = 1; i < vLen; i++){
            int nextPos = upper_bound(nums.begin(), nums.end(), nums[cnt]) - nums.begin();
            if(nextPos < vLen){
                nums[++cnt] = nums[nextPos];
            }
            else break;
        }
        return cnt + 1;
    }
};