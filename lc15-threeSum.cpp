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
        
        // ruling out those absolutely impossible elements from both front and rear
        // but this part brings 12ms more runtime than without it in method 2 (sad)
/*         while(l < r){
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
        if(r - l < 2)  return slnSet; */

        // Method 1 : traver the first 2 elements and binary search the 3rd
        // very slow(236ms), not very memo saving
/*         for(int i = l; i < r - 1; i++){
            if(nums[i] > 0)    break;
            if(i > l && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < r; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] < 0 && nums[i] + nums[j] > 0)    break;
                int twoSum = nums[i] + nums[j];
                int third = binarySearch(nums, j + 1, r, 0 - twoSum);
                if(third == -1) continue;
                else{
                    vector<int> triplet = {nums[i], nums[j], nums[third]};
                    slnSet.push_back(triplet);
                }
            }
        } */
        
        //Method 2: opposite growing pointer p and q to search the latter 2 elements. O(n^2) 100ms
        for(int i = l; i < r - 1; i++){
            if(nums[i] > 0) break;
            if(i > l && nums[i] == nums[i - 1]) continue;
            int p = i + 1, q = r;
            while(p < q){
                if(p > i + 1 && nums[p] == nums[p - 1]){
                    p++;
                    continue;
                }
                int sum2 = nums[p] + nums[q];
                if(nums[i] + sum2 < 0)  p++;
                else if(nums[i] + sum2 > 0) q--;
                else{
                    vector<int> triplet = {nums[i], nums[p], nums[q]};
                    slnSet.push_back(triplet);
                    p++;
                    q--;
                }
            }
        }
        return slnSet;
    }

    // for method 1
/*     int binarySearch(vector<int>& nums, int left, int right, int target){
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
    } */
};
int main(){
    vector<int> input = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
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