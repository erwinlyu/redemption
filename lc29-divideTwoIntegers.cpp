#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {

        // reference: https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations

        // very smart method to handle case that dividend is INT_MIN
        if(dividend == INT_MIN){
            if(divisor == -1)   return INT_MAX;
            if(divisor == 1)    return INT_MIN;
            else return ((divisor & 1) == 1) ? divide(dividend + 1, divisor) : divide(dividend >> 1, divisor >> 1);
        }

        // no need for (dividend > 0) ^ (divisor > 0) because the ^'s priority is lower than > and <'s
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1, ans = 0;

        // need to define dvd, dvs, temp and m as long instead of int 
        // to handle the case like (INT_MAX, x), for temp <<= 1 would overflow when int-temp
        // is (INT_MAX + 1) / 2
        long long dvd = labs(dividend), dvs = labs(divisor);
        while(dvd >= dvs){
            long long temp = dvs, m = 1;
            while(temp << 1 <= dvd){
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }

        // (~val + 1) gets the opposite number of val
        if(ans == -1)   ans = ~ans + 1;
        return ans;
    }
};
int main(){
    Solution sln;
    cout << sln.divide(2147483647, 2);
    return 0;
}