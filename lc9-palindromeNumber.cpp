#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // store each digit into a vector
        // poor performance in both runtime and memory consuming
/*         if(x < 0)   return false;
        if(x == 0)  return true;
        vector<int> digits;
        int cpy = x;
        while(cpy > 0){
            digits.push_back(cpy % 10);
            cpy /= 10;
        }
        int i = 0, j = digits.size() - 1;
        bool palindromic = true;
        while(i <= j){
            if(digits[i] != digits[j]){
                palindromic = false;
                break;
            }
            else{
                i++;
                j--;
            }
        }
        return palindromic; */

        // Revert half of the number
        // much faster and memory saving
        if(x < 0 || (x % 10 == 0 && x != 0))   return false;
        if(x == 0)  return true;
        int reverted = 0;
        while(x > reverted){
            reverted = reverted * 10 + (x % 10);
            x = x / 10;
        }
        return (x == reverted || x == (reverted / 10));
    }
};
int main(){
    int num;
    cin >> num;
    Solution sln;
    cout << sln.isPalindrome(num);
    return 0;
}