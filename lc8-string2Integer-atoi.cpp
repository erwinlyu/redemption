#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int strLen = str.length();
        if(strLen == 1){
            if(str[0] - '0' >= 0 && str[0] - '0' <= 9)  return str[0] - '0';
            else    return 0;
        }
        int p = 0;
        bool negative = false;
        while(str[p] == ' ' && p < strLen)  p++;
        if(p == strLen) return 0;
        if(p == strLen - 1){
            if(str[p] - '0' >= 0 && str[p] - '0' <= 9)  return str[p] - '0';
            else    return 0;
        }
        if(str[p] != '-' && str[p] != '+' && !(str[p] - '0' >= 0 && str[p] - '0' <= 9)) return 0;\
        //tricky case: "-+1"
        if(str[p] == '-' || str[p] == '+'){
            if(str[p] == '-')   negative = true;
            p++;
        }
        vector<int> num;
        while(p < strLen){
            if(str[p] - '0' >= 0 && str[p] - '0' <= 9){
                if(p + 1 < strLen){

                }
                num.push_back(str[p] - '0');
                p++;
            }
            else    break;
        }
        if(num.size() == 0) return 0;
        // tricky case: "20000000000000000000" (long long int overflow)
        // and "  0000000000012345678"
        // attention: "  0000000000012345678" as inputs should get 12345678
        long long output = 0;
        for(int i = 0; i < num.size(); i++){
            output *= 10;
            output += num[i];
            
            if(output > INT_MAX)   break;
        }
        if(negative)   output *= -1;
        if(output < INT_MIN)    return INT_MIN;
        else if(output > INT_MAX)   return INT_MAX;
        else return output;
    }
};
int main(){
    string str;
    getline(cin, str);
    Solution sln;
    cout << sln.myAtoi(str);
    return 0;
}