#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int integer = 0, index = 0, sLen = s.length();
        while(index < sLen){
            if(s[index] == 'M'){
                integer += 1000;
                index++;
            }
            else if(s[index] == 'D'){
                integer +=500;
                index++;
            }
            else if(s[index] == 'C'){
                if(index + 1 < sLen && s[index + 1] == 'M'){
                    integer += 900;
                    index += 2;
                }
                else if(index + 1 < sLen && s[index + 1] == 'D'){
                    integer += 400;
                    index += 2;
                }
                else{
                    integer += 100;
                    index++;
                }
            }
            else if(s[index] == 'L'){
                integer += 50;
                index++;
            }
            else if(s[index] == 'X'){
                if(index + 1 < sLen && s[index + 1] == 'C'){
                    integer += 90;
                    index += 2;
                }
                else if(index + 1 < sLen && s[index + 1] == 'L'){
                    integer += 40;
                    index += 2;
                }
                else{
                    integer += 10;
                    index++;
                }
            }
            else if(s[index] == 'V'){
                integer += 5;
                index++;
            }
            else{
                if(index + 1 < sLen && s[index + 1] == 'X'){
                    integer += 9;
                    index += 2;
                }
                else if(index + 1 < sLen && s[index + 1] == 'V'){
                    integer += 4;
                    index += 2;
                }
                else{
                    integer += 1;
                    index++;
                }
            }
        }
        return integer;
    }
};

int main(){
    string s = "MCMXCIV";
    Solution sln;
    cout << sln.romanToInt(s);
    return 0;
}