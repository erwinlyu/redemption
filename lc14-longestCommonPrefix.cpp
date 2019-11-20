#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())    return "";
        if(strs.size() == 1)    return strs[0];
        int strnum = strs.size();
        int index = 0;
        bool stop = false;
        string output;
        while(index <= strs[0].length()){
            for(int i = 0; i < strnum - 1; i++){
                cout << i << endl;
                if(index >= strs[i].length() || index >= strs[i + 1].length()){
                    stop = true;
                    break;
                }
                if(strs[i][index] != strs[i + 1][index]){
                    stop = true;
                    break;
                }
                if(i == strnum - 2){
                    output += strs[0][index];
                }
            }
            if(stop)    return output;
            else    index++;
        }
        return output;
    }
};
int main(){
    vector<string> strs = {"flower","flow","flight"};
    Solution sln;
    cout << sln.longestCommonPrefix(strs);
    return 0;
}