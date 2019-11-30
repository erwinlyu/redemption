#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {

        // method 1: brute force
/*         // the order of the following two lines should not be reversed, for case "" "" returns 0
        // here's why:
        // "we will return 0 when needle is an empty string, this is consistent to
        // C's strstr() and Java's indexOf()"
        if(needle.empty())  return 0;
        if(haystack.empty())    return -1;

        int hayLen = haystack.length(), ndlLen = needle.length();
        if(hayLen < ndlLen) return -1;
        for(int i = 0; i <= hayLen - ndlLen; i++){
            if(haystack[i] == needle[0]){
                if(haystack.substr(i, ndlLen) == needle)    return i;
            }
        }
        return -1; */

        // method 2: KMP algorithm
        // reference: Introduction to Algorithm Edition 3
        if(needle.empty())  return 0;
        if(haystack.empty())    return -1;
        int n = haystack.length(), m = needle.length();
        vector<int> pi = computePrefix(needle);
        int q = -1;
        for(int i = 0; i < n; i++){
            while(q >= 0 && needle[q + 1] != haystack[i]){
                q = pi[q] - 1;
            }
            if(needle[q + 1] == haystack[i])    q++;
            if(q == m - 1)  return i - m + 1;
        }
        return -1;
    }
    vector<int> computePrefix(string pattern){
        vector<int> pi(pattern.length());
        pi[0] = 0;
        int k = 0;
        for(int q = 2; q <= pattern.length(); q++){
            cout << "in here" << endl;
            while(k > 0 && pattern[k] != pattern[q - 1])    k = pi[k - 1];
            if(pattern[k] == pattern[q - 1])    k = k + 1;
            pi[q - 1] = k;
        }
        for(auto i : pi){
            cout << i << " ";
        }
        cout << endl;
        return pi;
    }
};
int main(){
    string t = "mississippi";
    string p = "issip";
    Solution sln;
    int a = sln.strStr(t, p);
    cout <<"pos is: " << a << endl;
    return 0;
}