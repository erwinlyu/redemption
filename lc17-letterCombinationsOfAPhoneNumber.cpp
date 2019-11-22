#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> vofs;
    vector<vector<char>> lut = {{'a','b','c'}, {'d','e','f'}, 
                            {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, 
                            {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
    vector<string> letterCombinations(string digits) {
        // in case empty input
        if(digits.empty())  return vofs;
        string str;
        dfs(0, 0, digits, str);
        return vofs;
    }
    void dfs(int depth, int index, string digits, string str){
        cout << "current depth " << depth << endl;
        if(depth == digits.size() - 1){
            while(index < lut[digits[depth] - '2'].size()){
                cout << "current index is " << index << endl;
                str += lut[digits[depth] - '2'][index];
                vofs.push_back(str);
                str.pop_back();
                index++;
            }
            return ;
        }
        else{
            while(index < lut[digits[depth] - '2'].size()){
                cout << "current index is " << index << endl;
                str += lut[digits[depth] - '2'][index];
                dfs(depth + 1, 0, digits, str);
                str.pop_back();
                index++;
            }
            return ;
        }
    }
};
int main(){
    string number = "23";
    Solution sln;
    vector<string> result = sln.letterCombinations(number);
    cout << result.size();
    return 0;
}