#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        nLen = nums.size();
        vector<int> row;
        //backtracking(0, res, row, nums);    // recursive
        //res = iteration(nums);  //iterative
        res = ite_over_one_bit(nums);
        return res;
    }

private:
    int nLen;

    // method 1: recursive, similar structure as lc46, lc47, etc.
    // references:https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
    // https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
    void backtracking(int idx, vector<vector<int>>& subsets, vector<int>& subset, vector<int>& nums){
        subsets.push_back(subset);
        for(int i = idx; i < nLen; ++i){
            subset.push_back(nums[i]);
            backtracking(i + 1, subsets, subset, nums);
            subset.pop_back();
        }
    }

    //method 2: recursive way.
    // enumerate each element and append it to each existing subset, 
    // which composes a new subset.
    // reference: https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
    vector<vector<int>> iteration(vector<int>& nums){
        vector<vector<int>> subsets = {{}};
        vector<int> subset = {};
        for(int num : nums){
            int n = subsets.size();
            for(int i = 0; i < n; ++i){
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }
        return subsets;
    }

    // method 3: bit-manipulation
    // very genius algorithm. orz

    // To give all the possible subsets, 
    // we just need to exhaust all the possible combinations of the numbers. 
    // And each number has only two possibilities: 
    // either in or not in a subset. And this can be represented using a bit.

    // Using [1, 2, 3] as an example, 
    // 1 appears once in every two consecutive subsets, 
    // 2 appears twice in every four consecutive subsets, 
    // and 3 appears four times in every eight subsets (initially all subsets are empty):

    // reference: https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
    vector<vector<int>> bit_manip(vector<int>& nums){
        int n = nums.size(), p = 1 << nLen;
        vector<vector<int>> subsets(p);
        for(int i = 0; i < p; ++i){
            for(int j = 0; j < n; ++j){
                if((i >> j) & 1)    subsets[i].push_back(nums[j]);
            }
        }
        return subsets;
    }

    // method 4: another genius bit-manipulation iteration algorithm.. orz..
    // in the comments zone of reference link above. by stefan pochmann...
    vector<vector<int>> ite_over_one_bit(vector<int>& nums){
        int n = nums.size(), num_subsets = 1 << n;
        vector<vector<int>> subsets(num_subsets);
        for(int i = 0; i < n; ++i)
            for(int step = 1 << i, start = 0; start < num_subsets; start += 2 * step)
                for(int j = start; j < start + step; ++j)
                    subsets[j].push_back(nums[i]);
        return subsets;
    }
};

int main(){
    vector<int> input = {1,2,3};
    Solution sln;
    vector<vector<int>> output = sln.subsets(input);
    for(vector<int> row : output){
        for(int element : row)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}