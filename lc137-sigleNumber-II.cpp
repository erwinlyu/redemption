#include <vector>
using namespace std;
// refs:
// 1) https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
//      this link gives a generic bitwise operation solution to this sort of problems.
// 2) the first comment of https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
//      this is explanation easier to grasp of this problem, core idea is the same as the first link.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask;
        for (int num : nums) {
            x2 ^= (x1 & num);
            x1 ^= num;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};