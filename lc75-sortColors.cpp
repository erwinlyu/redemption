#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    // The idea is to sweep all 0's to the left and all 2's to the right, 
    // then all 1's are left in the middle.
    // reference: https://leetcode.com/problems/sort-colors/discuss/26472/Share-my-at-most-two-pass-constant-space-10-line-solution
    
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for(int i = 0; i < two; ++i){
            while(nums[i] == 2 && i < two) swap(nums[i], nums[two--]);
            while(nums[i] == 0 && i > zero)    swap(nums[i], nums[zero++]);
        }
    }
};

int main(){
    vector<int> input = {2,0,2,1,1,0};
    Solution sln;
    sln.sortColors(input);
    for(int item : input)   cout << item << " ";
    return 0;
}