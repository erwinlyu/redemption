#include <map>
using namespace std;
class Solution {
public:
    // method 1:
    // return sort(s1.begin(), s1.end()) == sort(s2.begin(), s2.nd());
    
    // method 2: map
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        map<char, int> char_map;
        for(char c : s1) {
            if (char_map.find(c) == char_map.end()) {
                char_map[c] = 1;
            }
            else {
                char_map[c]++;
            }
        }
        for (char c : s2) {
            if (char_map.find(c) == char_map.end())
                return false;
            else {
                char_map[c]--;
                if (char_map[c] < 0)
                    return false;
            }
        }
        return true;
    }
};