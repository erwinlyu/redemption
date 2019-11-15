#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        //x cannot equal INT32_MIN, for the range of int is -2^32 to 2^32-1 i.e. -2147483648~2147483647
        //and INT32_MIN will overflow when multiplied by -1
        if(x > INT32_MAX || x <= INT32_MIN)  return 0;
        bool neg = false;
        vector<int> digits;
        if(x < 0){
            neg = true;
            x = -1 * x;
        }
        while(x > 0){
            int temp = x % 10;
            digits.push_back(temp);
            x = x / 10;
        }
        int result = 0;
        for(int i = 0; i < digits.size(); i++){
            if(result > INT32_MAX / 10) return 0;   //for some 10-digit number woudle overflow when reversed
            result *= 10;
            result += digits[i];
        }
        if(neg) result *= -1;
        return result;
    }
};

int main(){
    int input;
    cin >> input;
    Solution sln;
    cout << sln.reverse(input);
    return 0;
}