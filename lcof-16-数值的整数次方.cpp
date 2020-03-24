using namespace std;
// 快速幂
class Solution {
public:
    // 自己的解法,递归形式
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) return 1.0;
        if (n == 1) return x;
        if (n < 0) {
            x = 1.0 / x;
            if (n % 2 == 0) {
                x *= x;
                n /= 2;
            }
            n = ~n + 1; // 如果直接对n取反加1会在n==INT_MIN时会溢出
        }
        if (n % 2 == 0) return myPow(x * x, n >> 1);
        else    return x * myPow(x, n - 1);
    }

    // 迭代形式
    double iterative_fashion(double base, int exponent) {
        if (exponent == 1 || base == 1.0)   return 1.0;
        if (exponent < 0) {
            base = 1.0 / base;
            if (exponent & 1 == 0) {
                base *= base;
                exponent /= 2;
            }
            exponent = ~exponent + 1;
        }
        double res = 1.0;
        while (exponent > 1) {
            if (exponent & 1 == 1)   res *= base;
            base *= base;
            exponent >>= 1;
        }
        return res;
    }
};