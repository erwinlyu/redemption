#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)  return res;
        recur("", n, 0);
        return res;
    }
private:
    vector<string> res;

    void recur(string str, int left, int right){
        // recursive method.
        // key idea is to make sure the number of '(' exceeds the number of ')' in the existing string.
        // maintain two parameters, the remaining number of left and right parentheses which could
        // be added to the tail of existing string.
        // track their number until the both meet 0.
        // reference: https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
        if(left == 0 && right == 0){
            res.push_back(str);
            return ;
        }
        if(left > 0)    recur(str + '(', left - 1, right + 1);
        if(right > 0)   recur(str + ')', left, right - 1);
    }

    /**
     * 带剪枝的回溯
     * 一个合法的括号组合应该满足如下两个性质:
     *      1) 组合中左右括号的数量相等
     *      2) 这个组合的任意长度的前缀子串中左括号的数量大于等于右括号的数量
    */
    void backtrack(string& pmt, int left, int right) {   // 使用left和right来记录剩余的左右括号的数量
        if (left > right)   return; // 如果左括号剩下的多,那么肯定是不合法的
        if (left < 0 || right < 0)  return; // 左右括号剩余数量小于0,不合法的
        if (left == 0 && right == 0) {  // 左右括号都恰好用完,得到了一个合法的括号排列
            res.push_back(pmt);
            return;
        }

        // 尝试添加一个左括号
        pmt.push_back('('); // 添加
        backtrack(pmt, left - 1, right);
        pmt.pop_back(); // 撤销添加

        // 尝试添加一个右括号
        pmt.push_back(')'); // 添加
        backtrack(pmt, left, right - 1);
        pmt.pop_back(); // 撤销添加
    }
};