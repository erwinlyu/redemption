#include <string>
using namespace std;
class Solution {
public:
// https://leetcode.com/problems/decode-ways/discuss/30358/Java-clean-DP-solution-with-explanation
    int numDecodings(string s) {
        if (s[0] == '0')   return 0;
        int sLen = s.size();
        if (sLen == 1)  return 1;
        int pre1 = 1, pre2 = 1, cur;
        for (int i = 1; i < sLen; ++i) {
            cur = 0;
            int curDig = s[i] - '0';
            int window = (s[i - 1] - '0') * 10 + curDig;
            if (1 <= curDig && curDig <= 9)     cur += pre1;
            if (10 <= window && window <= 26)   cur += pre2;
            pre2 = pre1;
            pre1 = cur;
            if (cur == 0)   return 0;
        }
        return cur;
    }
};