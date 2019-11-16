#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())   return "";
        if(s.length() == 1) return s;
        int maxLen = 0, start;
        for(int i = 0; i < s.length() - 1; i++){
            int tempLen = 1;
            int p = i - 1, q = i + 1;
            while(p >= 0 && q < s.length()){
                if(s[p] == s[q]){
                    tempLen += 2;
                    p--;
                    q++;
                }
                else    break;
            }
            if(tempLen > maxLen){
                maxLen = tempLen;
                start = i - (maxLen - 1) / 2;
            }
            if(s[i] == s[i + 1]){
                tempLen = 2;
                p = i - 1;
                q = i + 2;
                while(p >= 0 && q < s.length()){
                    if(s[p] == s[q]){
                        tempLen += 2;
                        p--;
                        q++;
                    }
                    else break;
                }
                if(tempLen > maxLen){
                    maxLen = tempLen;
                    start = i - (maxLen - 2) / 2;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    string str;
    Solution sln;
    getline(cin, str);
    string strr = sln.longestPalindrome(str);
    cout << strr << endl;
    return 0;
}