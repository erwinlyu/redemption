#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        string res = "";
        char int2char[2] = {'0', '1'};
        while (i >= 0 || j >= 0 || carry) {
            int temp = carry;
            if (i >= 0)     temp += a[i--] - '0';
            if (j >= 0)     temp += b[j--] - '0';
            carry = temp / 2;
            res += int2char[temp % 2];  // consumes less memory than res = int2char[] + res;
        }
        reverse(res.begin(), res.end());    // turs out reverse() takes more running time
        return res;
    }
};