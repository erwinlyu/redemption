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
        // little modification to the termination condition of dfs over the code below
        // which reduced rumtime significantly (0ms vs 8ms)
        // and saved a little memory (8.4MB vs 8.8MB)
        // both of them are currently state-of=the-art performance in leetcode
        if(depth == digits.length()){
            vofs.push_back(str);
            return ;
        }
/*         if(depth == digits.size() - 1){
            while(index < lut[digits[depth] - '2'].size()){
                str += lut[digits[depth] - '2'][index];
                vofs.push_back(str);
                str.pop_back();
                index++;
            }
            return ;
        } */

        while(index < lut[digits[depth] - '2'].size()){
            str += lut[digits[depth] - '2'][index];
            dfs(depth + 1, 0, digits, str);
            str.pop_back();
            index++;
        }
        return ;
    }
};
int main(){
    string number = "23";
    Solution sln;
    vector<string> result = sln.letterCombinations(number);
    cout << result.size();
    return 0;
}