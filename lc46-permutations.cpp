#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())    return res;
        visited.resize(nums.size());
        vector<int> permutation;
        //dfsBased(nums, permutation, visited, 0);
        swapBased(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<bool> visited = {false};

    // method 1: dfs method
    void dfsBased(vector<int>& nums, vector<int> pmt, vector<bool>& visited, int idx){
        if(pmt.size() == nums.size()){
            res.push_back(pmt);
            return ;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] == true)  continue;
            pmt.push_back(nums[i]);
            visited[i] = true;
            dfsBased(nums, pmt, visited, idx + 1);
            visited[i] = false;
            pmt.pop_back();
        }
    }

    // method 2: swap based method, a little bit slower than dfs yet consumes less memory
    // reference:https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
    // Basic idea: permutation of A[1..n] equals to
    // A[1] + permutation of (A[1..n] - A[1])
    // A[2] + permutation of (A[1..n] - A[2])
    // ...
    // A[n] + permutation of (A[1..n] - A[n]).
    void swapBased(vector<int>& nums, int idx){
        if(idx >= nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int i = idx; i < nums.size(); ++i){
            swap(nums[idx], nums[i]);
            swapBased(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};
int main(){
    vector<int> input = {1,2,3};
    Solution sln;
    vector<vector<int>> output = sln.permute(input);
    for(vector<int> item1 : output){
        for(int item2 : item1)  cout << item2 << " ";
        cout << endl;
    }
    return 0;
}