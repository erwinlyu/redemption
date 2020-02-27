#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // ref:https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time
        // 既然只允许constant space，那么就把nums本身当作hash table.
        // 把每个元素咦swap的形式放在正确的位置，如数字5就应该与nums[4]作swap.
        // 最后，遍历nums，第一个misplace的元素所在的位置+1就是first missing positive.
        int nSize = nums.size();
        for (int i = 0; i < nSize; ++i) {
            // 此处是while而不是if. 因为如果是if的话，交换来的元素如果不是“正确的”，那么接下来就进入下一个
            // 循环就会错过这个未正确处理的元素了.
            while (nums[i] > 0 && 
                   nums[i] < nSize && 
                   nums[nums[i] - 1] != nums[i]) {
                       swap(nums[i], nums[nums[i] - 1]);
                   }
        }
        for (int i = 0; i < nSize; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nSize + 1;
    }
};