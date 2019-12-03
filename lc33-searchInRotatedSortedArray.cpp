#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        int nLen = nums.size();
        int left = 0, right = nLen - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else   right = mid;
        }
        int pivot = left;
        left = 0;
        right = nLen - 1;

        // the loop condition should be <= instead of < to cope with 
        // the cases which contain only 1 number in the array.
        while(left <= right){
            int mid = (left + right) / 2;
            // very brilliant algorithm! difficult to come up with though.
            // according to my understanding, nums can be regard as a periodic array
            // so that the two part of nums alternate by the period of nums.size().
            // and the primary expression for realMid is:
            // ((right + pivot + left + pivot) % n ) / 2
            int realMid = (mid + pivot) % nLen;
            if(nums[realMid] == target) return realMid;
            else if(nums[realMid] < target)  left = mid + 1;

            // here, right should be assigned as mid-1 instead of mid because 
            // the loop condition is <= other than <, which otherwise
            // case like [....,0,1,2] with target=3 cannot be handled correctly.
            else    right = mid - 1;
        }
        return -1;
    }
};
int main(){
    Solution sln;
    vector<int> v = {4,5,6,7,0,1,2};
    int a = sln.search(v, 3);
    cout << a << endl;
    return 0;
}