#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        nLen = nums.size();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return subsets;
    }
private:
    vector<vector<int>> subsets;
    vector<int> subset;
    int nLen;

    // method 1: recursive method
    // similar structure to problem 78, 46, 47, but different in handling duplicates.
    void backtracking(vector<int>& nums, int begin) {
        subsets.push_back(subset);
        for (int i = begin; i < nLen; ++i) {
            // the line below is what's different from the recursive solution of problem78-subsets.
            // barely (nums[i]==nums[i-1]) is not correct.
            // "begin" literally means the first element of current subsets, 
            // and the element after it should not be its duplicate.
            if (i != begin && nums[i] == nums[i - 1])   continue;
            
            subset.push_back(nums[i]);
            backtracking(nums, i + 1);
            subset.pop_back();
        }
    }

    // method 2: iterative method
    // faster than recursive method
    // https://leetcode.com/problems/subsets-ii/discuss/30168/C%2B%2B-solution-and-explanation
    void iterative_method(vector<int>& nums) {
        subsets.push_back(vector<int>());
        int start = 0;
        for (int i = 0; i < nLen; ++i) {
            if (i == 0 || nums[i] != nums[i - 1])   start = 0;
            int end = subsets.size();
            while (start < end) {
                vector<int> clone = subsets[start++];
                clone.push_back(nums[i]);
                subsets.push_back(move(clone));
            }
        }
    }
};