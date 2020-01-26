#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n > 12)    return res;
        //dfs(s, 3, "");
        iteration(s);
        return res;
    }
private:
    vector<string> res;
    void dfs(string str, int level, string rst) {
        if (level < 0) {
            rst.pop_back(); // or rst.erase(rst.end() - 1); to delete the last char of a string.
            res.push_back(rst);
            return;
        }
        int slen = str.size();
        int lo = max(slen - 3 * level, 1);
        int hi = min(slen - level, 3);
        for (int i = lo; i <= hi; ++i) {
            string temp = str.substr(0, i);
            // temp.size() > 1 && temp[0] == '0' is to avoid a leading zero.
            if (stoi(temp) > 255 || temp.size() > 1 && temp[0] == '0')  return;
            dfs(str.substr(i, slen - i), level - 1, rst + temp + ".");
        }
    }

//https://leetcode.com/problems/restore-ip-addresses/discuss/30972/WHO-CAN-BEAT-THIS-CODE
    void iteration(string s) {
        for (int a = 1; a < 4; ++a)
        for (int b = 1; b < 4; ++b)
        for (int c = 1; c < 4; ++c) {
            int d = s.size() - a - b - c;
            if (0 < d && d < 4) {
                int vala = stoi(s.substr(0, a));
                int valb = stoi(s.substr(a, b));
                int valc = stoi(s.substr(a + b, c));
                int vald = stoi(s.substr(a + b + c, d));
                if (vala < 256 && valb < 256 && valc < 256 && vald < 256) {
                    string ans = to_string(vala) + "." +
                                 to_string(valb) + "." +
                                 to_string(valc) + "." +
                                 to_string(vald);
                    if (ans.size() == s.size() + 3) res.push_back(ans); //avoid leading zero.
                }
            }
        }
    }
};
int main() {
    string input = "010010";
    Solution sln;
    vector<string> output = sln.restoreIpAddresses(input);
    for (string str : output)   cout << str << endl;
    return 0;
}