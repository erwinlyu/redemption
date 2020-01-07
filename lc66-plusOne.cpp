#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int dLen = digits.size(), carry = 0;
        digits[dLen - 1] += 1;
        for (int i = dLen - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry) {
            vector<int> res(dLen + 1, 0);
            res[0] = 1;
            return res;
        }
        else    return digits;
    }
};