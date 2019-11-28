#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) { //pretty good time & space performance
        if(nums.empty())    return 0;
        int vLen = nums.size();
        int cnt = 0;
        for(int i = 0; i < vLen; i++){
            if(nums[i] != val){
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};