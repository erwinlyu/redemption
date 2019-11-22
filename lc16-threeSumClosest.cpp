#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0; i < nums.size() - 2; i++){
            //need condition diff != INT_MAX to manage the case like [1,1,1,1],0
            if(diff != INT_MAX && nums[i] > target)  break;
            int p = i + 1, q = nums.size() - 1;
            while(p < q){
                int twosum = nums[p] + nums[q];
                if(abs(nums[i] + twosum - target) < abs(diff))   diff = nums[i] + twosum - target;
                if(nums[i] + twosum < target)   p++;
                else if(nums[i] + twosum > target)  q--;
                else    return target;
            }
        }
        return target + diff;
    }
};
int main(){
    vector<int> nums = {1,1,1,1};
    int target = 0;
    Solution sln;
    cout << sln.threeSumClosest(nums, target);
    return 0;
}