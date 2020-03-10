#include <vector>
using namespace std;
class Solution {
public:
    // 2 pass, self-hash method.
    // appeared in Toutiao interview.
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        for (int num : nums) {
            int idx = abs(num) - 1;
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};