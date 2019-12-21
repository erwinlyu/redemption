#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> candidates;
        for(int i = 0; i < n; ++i)  candidates.push_back(i + 1);
        while(n >= 1){
            if(k == 0){
                while(!candidates.empty()){
                    res += int2char[candidates[candidates.size() - 1]];
                    candidates.erase(candidates.end() - 1);
                }
                break;
            }
            int head = (k - 1) / factorial(n - 1);
            res += int2char[candidates[head]];
            candidates.erase(candidates.begin() + head);
            k =  k % factorial(n-- - 1);
            //--n;
        }
        return res;
    }

private:
    char int2char[10] = {'0','1','2','3','4','5','6','7','8','9'};
    string res;
    int factorial(int n){
        if(n == 1 || n == 0)    return 1;
        else    return n * factorial(n - 1);
    }
};

int main(){
    Solution sln;
    cout << sln.getPermutation(3,3) << endl;
    return 0;
}