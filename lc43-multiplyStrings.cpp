#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// my own method, bad
/* class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")  return "0";
        string res = "0";
        for(int i = num2.length() - 1; i >= 0; --i){
            string tempStr = digitMultiply(num1, num2[i]);
            for(int j = 1; j < num2.length() - i; ++j){
                tempStr += "0";
            }
            res = strSum(res, tempStr);
        }
        return res;
    }
private:
    char int2char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string digitMultiply(string str, char digit){
        int strLen = str.length();
        int carry = 0;
        string tmpRes = "";
        for(int i = strLen - 1; i >= 0; --i){
            int a = str[i] - '0', b = digit - '0';
            int tmpMul = a * b + carry;
            carry = tmpMul / 10;
            tmpMul = tmpMul % 10;
            tmpRes = int2char[tmpMul] + tmpRes;
        }
        if(carry != 0)  tmpRes = int2char[carry] + tmpRes;
        return tmpRes;
    }
    string strSum(string str1, string str2){
        int carry = 0;
        int p = str1.length() - 1, q = str2.length() - 1;
        while(p >=0){
            int temp = str2[q] - '0' + str1[p] - '0' + carry;
            carry = temp / 10;
            temp = temp % 10;
            str2[q] = int2char[temp];
            p--;
            q--;
        }
        while(q >= 0){
            int temp = str2[q] - '0' + carry;
            carry = temp / 10;
            temp = temp % 10;
            str2[q] = int2char[temp];
            q--;
        }
        if(carry == 1)  str2 = "1" + str2;
        return str2;
    }
}; */

// an elegant and concise method
// reference:https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation
class Solution{
public:
    char int2char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string multiply(string num1, string num2){
        int nLen1 = num1.length(), nLen2 = num2.length();
        vector<int> resv(nLen1 + nLen2);
        fill(resv.begin(), resv.end(), 0);
        for(int i = nLen1 - 1; i >= 0; --i){
            for(int j = nLen2 - 1; j >= 0; --j){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int idx_hi = i + j, idx_lo = i + j + 1;
                mul += resv[idx_lo];
                resv[idx_hi] += mul / 10;
                resv[idx_lo] = mul % 10;
            }
        }
        string resstr = "";
        for(auto item : resv)   if(!(resstr.length() == 0 && item == 0))    resstr += int2char[item];
        return resstr.length() == 0 ? "0" : resstr;
    }
};
int main(){
    string a = "123";
    string b = "456";
    Solution sln;
    cout << sln.multiply(a, b);
    return 0;
}