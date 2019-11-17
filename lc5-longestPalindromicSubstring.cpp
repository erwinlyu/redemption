#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // brute force 
        // (check each point as the center point or between the center pair of a palindrome)
/*         if(s.empty())   return "";
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
        return s.substr(start, maxLen); */


        //Manacher's algorithm  O(n) O(n)
        //much faster than brute force (12ms vs 28ms)
        //little bit more memory than brute force(10.1MB vs 8.9MB)

        //refrences:
        //https://medium.com/hackernoon/manachers-algorithm-explained-longest-palindromic-substring-22cb27a5e96f
        //https://blog.csdn.net/HappyRocking/article/details/82622881

        if(s.empty())   return "";
        if(s.length() == 1) return s;
        string oddenized = oddenize(s);
        int slength = oddenized.length();
        int maxLen = 0, position = 0;
        vector<int> m;
        m.resize(slength);
        int c = 0, r = 0;
        for(int i = 1; i < slength; i++){
            int mirror = 2 * c - i;
            //the core idea of manacher's algorithm, determine the minumum certain possible
            //expansion distance of each node
            if(i < r){
                m[i] = min(m[mirror], r - i);
            }

            //try to expand the expansion of node i
            int templ = i - (m[i] + 1);
            int tempr = i + (m[i] + 1);
            while(templ >= 0 && tempr < slength && oddenized[templ] == oddenized[tempr]){
                m[i]++;
                templ--;
                tempr++;
            }

            //if i expands beyond the current right boundry, update center and right
            //as well as the maxlen of palindrome
            if(i + m[i] > r){
                c = i;
                r = i + m[i];
                if(m[i] > maxLen){
                    maxLen = m[i];
                    position = i;
                }
            }
        }
        string sub = oddenized.substr(position - maxLen, 2 * maxLen + 1);
        int index;
        while((index = sub.find('#')) != string::npos){
            sub.erase(index, 1);
        }
        return sub;
    }

    string oddenize(string s){
        string str;
        for(int i = 0; i < s.length(); i++){
            str += "#";
            str += s[i];
        }
        str.append("#");
        return str;
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