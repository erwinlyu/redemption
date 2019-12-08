#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// my own recursive method, slow and memory wasting
/* class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        dfs(res, candidates, v, 0, 0, target);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> candidates, vector<int>& current, int pos, int sum, int target){
        if(sum + candidates[pos] == target){
            current.push_back(candidates[pos]);
            res.push_back(current);
            current.pop_back();
            return ;
        }
        else if(sum + candidates[pos] < target){
            current.push_back(candidates[pos]);
            dfs(res, candidates, current, pos, sum + candidates[pos], target);
        }
        else    return ;
        if(!current.empty())    current.pop_back();
        if(pos + 1 < candidates.size())
            dfs(res, candidates, current, pos + 1, sum, target);
        else    return ;
    }
}; */

// a general approach learnt from leetcode
// concise, clearer, faster and less memory consuming
class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        if(candidates.empty() || candidates[0] > target)    return res;
        this->tgt = target;
        vector<int> tmp;
        backtrack(candidates, tmp, 0, 0);
        return res;
    }
private:
    int tgt;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& tmp, int sum, int idx){
        if(sum == tgt){
            res.push_back(tmp);
            return ;
        }
        for(int i = idx; i < nums.size(); ++i){
            if(sum + nums[i] > tgt) break;
            else{   // sum + nums[i] <= tgt
                tmp.push_back(nums[i]);
                backtrack(nums, tmp, sum + nums[i], i);
                tmp.pop_back();
            }
        }
    }
};

int main(){
    vector<int> a = {2,3,5};
    int target = 8;
    Solution sln;
    vector<vector<int>> res = sln.combinationSum(a, target);
    cout << res.size() << endl;
    return 0;
}