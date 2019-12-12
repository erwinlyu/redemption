#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())    return res;
        sort(nums.begin(), nums.end());
        swapBased(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void swapBased(vector<int>& nums, int idx){
        if(idx >= nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int i = idx; i < nums.size(); ++i){
            //if(i > idx && nums[i] == nums[i - 1]) continue;
            //if(i > idx && nums[i] == nums[idx]) continue;

            // the 2 noted lines of code above are not enough to avoid duplicate permutations.
            // have to make sure all the elements between idx and i not equals to nums[i],
            // otherwise duplicate would happen.

            // though nums is sorted in the first place, it can be out of order during recursions,
            // that is why the above 2 lines may lapse in some cases.
            // references:
            // https://leetcode.com/problems/permutations-ii/discuss/121739/C++-backtracking-solution-beat-95-with-explanation-(no-extra-spacememory-to-record-choice)
            // https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines
            if(i > idx && gotDup(nums, idx, i)) continue;

            swap(nums[idx], nums[i]);
            swapBased(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
    bool gotDup(vector<int>& nums, int begin, int idx){
        for(int i = begin; i < idx; ++i){
            if(nums[idx] == nums[i])  return true;
        }
        return false;
    }
};
int main(){
    vector<int> input = {0,1,0,0,9};    //{1,1,2} {1,1,2,2} {3,3,0,3} {-1,2,-1,2,1,-1,2,1} {0,1,0,0,9} {-1,2,0,-1,1,0,1}
    Solution sln;
    vector<vector<int>> output = sln.permuteUnique(input);
    for(vector<int> item1 : output){
        for(int item2 : item1)  cout << item2 << " ";
        cout << endl;
    }
    return 0;
}