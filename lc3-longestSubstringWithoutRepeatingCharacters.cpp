#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0; //in case the input string is empty
        int maxlen = 0;
        vector<int> dp;
        dp.resize(s.length());
        dp[0] = 1;
        for(int i = 1; i < s.length(); i++){
            dp[i] = dp[i - 1] + 1;
            for(int j = i - dp[i - 1]; j < i; j++){
                if(s[j] == s[i]) dp[i] = i - j;
            }
        }
        for(int i = 0; i < dp.size(); i++){
            if(dp[i] > maxlen)  maxlen = dp[i];
        }
        return maxlen;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sln;
    printf("%d\n", sln.lengthOfLongestSubstring(s));
    return 0;
}