#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())    return 0;
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};
int main(){
    vector<int> input = {1,3,5,6};
    Solution sln;
    int output = sln.searchInsert(input, 0);
    cout << output << endl;
    return 0;
}