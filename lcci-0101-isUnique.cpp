#include <string>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        int mark = 0;
        for (char c : astr) {
            // 这题只涉及到'a'-'z',所以int(32bits)是够用的
            // 可显示的ASCII字符是从32-126的
            // 如果astr覆盖了全部的可显示字符,那么一个unsigned long long都不够(64bit),要两个
            int move_bit = c - 'a';

            // 注意:&的优先级(第十级别)比!=(第九级别)还低,所以与运算的括号不可缺少
            if ((mark & (1 << move_bit)) != 0)    return false;

            else    mark |= (1 << move_bit);
        }
        return true;
   }
};