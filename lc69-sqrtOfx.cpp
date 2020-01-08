#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)   return x;
        return sqrt_with_newton(x);
    }

private:
    int sqrt_with_bs(int x) {
        // it turns out that finding the lower and upper boundry of x, which are lo
        // and hi, respectively, takes too much more time and saves only a little memory.
/*         int cnt = 0;
        while ((1 << cnt) <= x && cnt < 31) cnt++;
        int lo = 1 << (cnt - 1) / 2, hi = lo << 1; */

        int lo = 1, hi = INT_MAX;
        while (lo < hi) {
            cout << lo << " " << hi << endl;
            int mid = lo + (hi - lo) / 2;

            // the essence of this binary search here is to compare mid and (x / mid)
            // instead of comparing (mid*mid) and x, the latter would meet int overflow error.
            int quotient = x / mid;
            
            if (mid == quotient)  return mid;
            else if (mid < quotient)  lo = mid + 1;
            else    hi = mid;
        }
        return lo - 1;
    }

    /* Newton's method still stands in integer division only cases, which
        I did'nt expect.
        very elegant method.
        reference: https://leetcode.com/problems/sqrtx/discuss/25057/3-4-short-lines-Integer-Newton-Every-Language */
    int sqrt_with_newton(int x) {
        long r = x;
        while (r * r > x) 
            r = (r + x / r) / 2;
        return r;
    }
};

int main() {
    Solution sln;
    cout << sln.mySqrt(8); //2147395599
    return 0;
}