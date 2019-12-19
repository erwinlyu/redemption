#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordLen = 0;
        if(s.empty())   return wordLen;
        for(int i = s.length() - 1; i >= 0; --i){
            if(s[i] == ' '){
                if(wordLen != 0)    break;
                else    continue;
            }
            wordLen++;
        }
        return wordLen;
    }
};
int main(){
    string input = "asd af helloworld             ";
    Solution sln;
    cout << sln.lengthOfLastWord(input);
    return 0;
}