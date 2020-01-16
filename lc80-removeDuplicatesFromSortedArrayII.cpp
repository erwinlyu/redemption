#include <vector>
using namespace std;
class Solution {
public:
    // reference:https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby
    // this method can be generalized to k-most duplicates problem.
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums) {
            if (i < 2 || n > nums[i - 2]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};