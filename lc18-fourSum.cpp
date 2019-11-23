#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        for(int i = l; i < r - 2; i++){

            // the following line and the similar one in the second loop reduced rumtime(28ms vs 44ms)
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)  break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < r - 1; j++){
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)  break;
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                // this mechanism suits for the situation that target >= 0 only
                // and it does not save much runtime(reduced 4ms), takes 0.1MB extra memroy
                //if(target >= 0 && nums[i] + nums[j] > target)   break;

                int p = j + 1, q = r;
                while(p < q){
                    int twoSum = nums[p] + nums[q];
                    if(p > j + 1 && nums[p] == nums[p - 1]){
                        p++;
                        continue;
                    }
                    if(nums[i] + nums[j] + twoSum < target) p++;
                    else if(nums[i] + nums[j] + twoSum > target)    q--;
                    else{
                        vector<int> combination = {nums[i], nums[j], nums[p], nums[q]};
                        res.push_back(combination);
                        p++;
                        q--;
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    vector<int> input = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;
    Solution sln;
    vector<vector<int>> res = sln.fourSum(input, target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}