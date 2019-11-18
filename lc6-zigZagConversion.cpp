#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution{
public:
    string convert(string s, int numRows){
        // pay attention to the cases that numRows is 1, which lead to p == 0 and
        // that is illegal for i % p in the following codes
        // this method is neither fast nor memory saving
        if(numRows == 1)    return s;
        int period = 2 * numRows - 2;
        vector<string> sv;
        int sLength = s.length();
        sv.resize(sLength);
        for(int i = 0; i < sLength; i++){
            int index = i % period;
            if(index <= numRows - 1) sv[index] += s[i];
            else    sv[period - index] += s[i];
        }
        string str;
        for(int i = 0; i < sv.size(); i++)  str += sv[i];
        return str;
    }
};

int main(){
    string input;
    int numRows;
    cin >> input;
    cin >> numRows;
    Solution sln;
    cout << sln.convert(input, numRows);
    return 0;
}