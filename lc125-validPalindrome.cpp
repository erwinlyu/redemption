#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {

        // method 1: my own method. using vector.
        vector<char> encodeArr;
        for (int i = 0; i < s.size(); ++i) {
            if ('0' <= s[i] && s[i] <= '9')         encodeArr.push_back(s[i]);
            else if ('a' <= s[i] && s[i] <= 'z')    encodeArr.push_back(s[i]);
            else if ('A' <= s[i] && s[i] <= 'Z')    encodeArr.push_back(s[i] + 'a' - 'A');
            else    continue;
        }
        int vsize = encodeArr.size();
        for (int i = 0; i < vsize / 2; ++i) {
            if (encodeArr[i] != encodeArr[vsize - 1 - i])   return false;
        }
        return true;

        // method 2: in-place method. using functions: isalnum() and tolower().
        int head = 0, tail = s.size() - 1;
        while (head <= tail) {
            if (!isalnum(s[head]))  head++;
            if (!isalnum(s[tail]))  tail--;
            if (isalnum(s[head]) && isalnum(s[tail])) {
                if (tolower(s[head]) != tolower(s[tail]))   return false;
                head++;
                tail--;
            }
        }
        return true;
    }
};