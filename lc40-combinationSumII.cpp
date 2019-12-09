#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if(candidates.empty() || candidates[0] > target)    return res;
        this->tgt = target;
        vector<int> temp;
        backtrack(candidates, temp, 0, 0);
        return res;
    }
private:
    int tgt;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& temp, int sum, int idx){
        if(sum == tgt){
            res.push_back(temp);
            return ;
        }

        // two methods to avoid duplicate results.
        // the 1st: make sure i increments to the next first non-equal element.
        // the 2nd: make sure each iteration starts from the element which is smaller than its successor element in the candidates.
        // the 2nd method is a little bit faster,
        // though the 1st method is fast enough (faster than 99% submissions).

        // the 1st method:
/*         int i = idx;
        while(i < nums.size()){
            if(sum + nums[i] > tgt) break;
            temp.push_back(nums[i]);
            backtrack(nums, temp, sum + nums[i], i + 1);
            temp.pop_back();
            vector<int>::iterator it = upper_bound(nums.begin(), nums.end(), nums[i]);
            i = it - nums.begin();
        } */

        // the 2nd method:
        for(int i = idx; i < nums.size(); ++i){
            if(sum + nums[i] > tgt) break;
            if(i != idx && nums[i] == nums[i - 1])  continue;
            temp.push_back(nums[i]);
            backtrack(nums, temp, sum + nums[i], i + 1);
            temp.pop_back();
        }
    }
};
int main(){
    vector<int> input = {2,1,3,2,2,5};
    int target = 5;
    Solution sln;
    vector<vector<int>> a = sln.combinationSum2(input, target);
    for(vector<int> item1 : a){
        for(int item2 : item1)  cout << item2 << " ";
        cout << endl;
    }
    return 0;
}