#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // very brilliant single pass approach

        // firstly, find the first pair of two elements a[i] and a[i-1] from the backend of the vector
        // which satisfy a[i] > a[i - 1].
        // secondly, find the first element, a[j], in the right to a[i] which is greater than a[i-1];
        // thirdly, swap a[i] and a[j]
        // finally, reverse the elements between a[i+1] and a[a.size()-1].

        // reference: the solution page of this problem
        int nLen = nums.size();
        int probe = nLen - 1;
        while(probe > 0){
            if(nums[probe] > nums[probe - 1])   break;
            else probe--;
        }
        if(probe == 0){
            reverse(nums, 0, nLen - 1);
            return ;
        }
        int left = probe - 1;
        while(probe < nLen){

            // here the operator must be <= other than < because there is no point to swap two
            // elements if they were the same.
            if(nums[probe] <= nums[left])    break;
            else    probe++;
        }
        int right = probe - 1;
        swap(nums, left, right);
        reverse(nums, left + 1, nLen - 1);
        return ;
    }
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return ;
    }
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums, start, end);
            start++;
            end--;
        }
        return ;
    }
};
int main(){
    vector<int> testcase = {5,4,7,5,3,2};
    Solution sln;
    sln.nextPermutation(testcase);
    for(int i = 0; i < testcase.size(); i++)    cout << testcase[i] << " ";
    return 0;
}