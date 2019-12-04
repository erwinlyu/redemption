#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.empty())    return res;
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end() || *it != target)    return res;
        res[0] = it - nums.begin();
        it = upper_bound(nums.begin(), nums.end(), target);
        if(it == nums.end())    res[1] = nums.size() - 1;
        else    res[1] = it - nums.begin() - 1;
        return res;
    }
};
int main(){
    vector<int> input = {5,7,7,8,8,10};
    Solution sln;
    vector<int> output = sln.searchRange(input, 6);
    cout << output[0] << "  " << output[1] << endl;
    return 0;
}