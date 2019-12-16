#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())  return res;
        int height = matrix.size(), width = matrix[0].size();
        int bottleneck = min(height, width);
        for(int i = 0; i < (bottleneck + 1) / 2; ++i){
            for(int j = i; j < width - i; ++j)  res.push_back(matrix[i][j]);    //top
            for(int j = i + 1; j < height - i; ++j) res.push_back(matrix[j][width - 1 - i]);    //right
            if(i < height - 1 - i)
                for(int j = width - 2 - i; j >= i + 1; --j) res.push_back(matrix[height - 1 - i][j]);   //bottom
            if(i < width - 1 - i)
                for(int j = height - 1 - i; j >= i + 1; --j)    res.push_back(matrix[j][i]);    //left
        }
        return res;
    }
};