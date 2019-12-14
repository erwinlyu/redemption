#include <iostream>
#include <vector>
using namespace std;
// in the cases which n is very big(like 2147283647), simple recursion would cause stack-overflow issue
// the following recursion prevents such problem.
// reference:https://leetcode.com/problems/powx-n/discuss/450392/Java-Accepted-(Log2(n)-time)
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1.0;
        double temp = myPow(x, n / 2);
        if(n % 2 == 1)  return temp * temp * x;
        else if(n % 2 == -1)    return temp * temp / x;
        else    return temp * temp;
    }
};