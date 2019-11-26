#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        // backtracking method
        // key idea is to make sure the number of '(' exceeds the number of ')' in the existing string.
        // maintain two parameters, the remaining number of left and right parentheses which could
        // be added to the tail of existing string.
        // track their number until the both meet 0.
        // maintain two parameters, the remaining number of left and right parentheses which could
        // be added to the tail of existing string.
        // track their number until both of them meet 0.
        // reference: https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
        vector<string> result;
        if(n == 0)  return result;
        backtracking(result, "", n, 0);
        return result;
    }
    void backtracking(vector<string> &res, string str, int remainingLeft, int remainningRight){
        if(remainingLeft == 0 && remainningRight == 0){
            res.push_back(str);
            return ;
        }
        if(remainingLeft > 0)   backtracking(res, str + '(', remainingLeft - 1, remainningRight + 1);
        if(remainningRight > 0) backtracking(res, str + ')', remainingLeft, remainningRight - 1);
    }
};