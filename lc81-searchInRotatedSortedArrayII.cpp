#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())   return false;
        int nLen = nums.size();
        /* find the pivot first. */
        int pivot = 0;
        for (; pivot < nLen - 1; ++pivot)
            if (nums[pivot] > nums[pivot + 1])  break;
        // here, the second condition is necessary when dealing with cases like ([3,1],3).
        if (pivot == nLen - 2 && nums[pivot] <= nums[nLen - 1])  pivot++;

        if (nums[pivot] == target)  return true;
        else if (nums[pivot] < target)  return false;
        else {
            int lo, hi;
            if (nums[0] == target)  return true;
            /* dicide which part to be searched based on whether nums[pivot] < target. */
            else if (nums[0] < target) {
                lo = 0;
                hi = pivot;
            }
            else {
                lo = pivot + 1;
                hi = nLen - 1;
            }
            /* conventionally binary-search the corresponding part. */
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] == target)    return true;
                else if (nums[mid] < target)    lo = mid + 1;
                else    hi = mid - 1;
            }
            return false;
        }
    }

private:
    bool variant_of_bs(vector<int>& nums, int target) {
        /* learnt from leetcode submission page, more concise but slower. */
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)    return true;
            // if the right part is in order:
            else if (nums[mid] < nums[hi]) {
                // check if target is in the right part. if so, search this part.
                if (nums[mid] < target && nums[hi] >= target)    lo = mid + 1;
                //otherwise, switch to the left part.
                else    hi = mid - 1;
            }
            // if the left part is in order:
            else if (nums[mid] > nums[hi]) {
                // check if target is in the left part, if so, search this part.
                if (nums[mid] > target && nums[lo] <= target)   hi = mid - 1;
                // otherwise, switch to the right part.
                else    lo = mid + 1;
            }
            else hi--;  // nums[mid] == nums[hi]
        }
        return false;
    }
};

int main() {
    vector<int> input = {3,1};
    int target = 3;
    Solution sln;
    if (sln.search(input, target))  printf("good");
    return 0;
}