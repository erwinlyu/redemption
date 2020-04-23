#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        if(nums.empty())    return res;
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> permutation;
        //backtrack(nums, permutation, visited);
        swap_method(nums, 0);
        return res;
    }
private:
    vector<vector<int> > res;
    int n;

    // method 1: backtracking method
    void backtrack(vector<int>& nums, vector<int> pmt, vector<bool>& visited){
        if(pmt.size() == n){
            res.push_back(pmt);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(visited[i] == true)  continue;
            pmt.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, pmt, visited);
            pmt.pop_back();
            visited[i] = false;
        }
    }

    // method 2: swap based method, consumes less memory.
    // reference:https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
    // Basic idea: permutation of A[1..n] equals to
    // A[1] + permutation of (A[1..n] - A[1])
    // A[2] + permutation of (A[1..n] - A[2])
    // ...
    // A[n] + permutation of (A[1..n] - A[n]).
    void swap_method(vector<int>& nums, int begin){
        if(begin >= n){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < n; ++i){
            swap(nums[begin], nums[i]);
            swap_method(nums, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }
};

int main(){
    vector<int> input{1,2,3,4,5};
    Solution sln;
    auto output = std::move(sln.permute(input));
    cout << output.size() << endl;
    for (auto row : output) {
        for (auto i : row)  cout << i << " ";
        cout << endl;
    }
    return 0;
}