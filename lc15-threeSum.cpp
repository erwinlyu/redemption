#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> slnSet;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums[nums.size() - 1] < 0 || nums[0] > 0) return slnSet;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            if(nums[l] + nums[r] + nums[r - 1] < 0){
                vector<int>::iterator low = lower_bound(nums.begin() + l, nums.begin() + r, 0 - (nums[r] + nums[r - 1]));
                l = low - nums.begin();
            }
            else if(nums[r] + nums[l] + nums[l + 1] > 0){
                vector<int>::iterator up = upper_bound(nums.begin() + l, nums.begin() + r, 0 - (nums[l] + nums[l + 1]));
                r = up - nums.begin() - 1;
            }
            else    break;
        }
        cout << l << " " << r << endl;
        if(r - l < 2)  return slnSet;
        for(int i = l; i < r - 1; i++){
            if(nums[i] > 0)    break;
            if(i > l && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < r; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] < 0 && nums[i] + nums[j] > 0)    break;
                int twoSum = nums[i] + nums[j];
                cout << "current i and j is " << i << " " << j << endl;
                int third = binarySearch(nums, j + 1, r, 0 - twoSum);
                if(third == -1) continue;
                else{
                    vector<int> triplet = {nums[i], nums[j], nums[third]};
                    slnSet.push_back(triplet);
                }
            }
        }
        return slnSet;
    }
    int binarySearch(vector<int>& nums, int left, int right, int target){
        cout << "diaoyongle" << endl;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target)  left = mid + 1;
            else right = mid;
        }
        if(left == right){
            if(nums[left] == target)    return left;
            else return -1;
        }
        return -1;
    }
};
int main(){
    vector<int> input = {0,0,0};
    Solution sln;
    vector<vector<int>> result =  sln.threeSum(input);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}