#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        matrix.resize(n);
        for(int i = 0; i < n; ++i)  matrix[i].resize(n);
        int cnt = 1;
        for(int i = 0; i < (n + 1) / 2; ++i){
            for(int j = i; j < n - i; ++j)  matrix[i][j] = cnt++;
            for(int j = i + 1; j < n - i; ++j)  matrix[j][n - 1 - i] = cnt++;
            for(int j = n - 2 - i; j >= i + 1; --j) matrix[n - 1 - i][j] = cnt++;
            for(int j = n - 1- i; j >= i + 1; --j)   matrix[j][i] = cnt++;
        }
        return matrix;
    }
};
int main(){
    Solution sln;
    vector<vector<int>> output = sln.generateMatrix(3);
    for(auto row : output){
        for(auto element : row) cout << element << " ";
        cout << endl;
    }
    return 0;
}