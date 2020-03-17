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

        /* 与上面代码具有相同的思想不过更简洁
        // 可以从掩码的角度去考虑,也可以从状态机的角度去考虑
        // ref分别是
        // https://zhuanlan.zhihu.com/p/113849406
        // https://zhuanlan.zhihu.com/p/113846542
        int once = 0, twice = 0;
        for (int x : nums) {
            once = (once ^ x) & (~twice);
            twice  = (twice ^ x) & (~once);
        }
        return once;
        */
    }

    // method 2: 逐位统计,不如位操作快但也是O(1)空间
    int method_2(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num : nums) {
                cnt += (num >> i) & 1;
            }
            res |= (cnt % 3) << i;
        }
        return res;
    }
};