#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        int pre = 0, cur = 1, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int sum = (pre + cur) % mod;
            pre = cur;
            cur = sum;
        }
        return pre;
    }
};