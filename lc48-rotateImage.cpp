#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // my own method, the most trivial way...
    // slow but memory-saving.
    // spent too much time on deciding the position of the elements to swap.
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < (n + 1) / 2; ++i){
            for(int j = i; j < n - i; ++j){
                swap(matrix[i][n - 1 - j], matrix[j][i]);
                swap(matrix[j][i], matrix[n - 1 - i][j]);
                swap(matrix[n - 1 - i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }

    // ************ fancy method 1 ************
    // reference:https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image

    // to rotate the matrix clockwisely:
    // first, turn the matrix upside dwon;
    // finally, transpose the matrix.
    void clockwise_rotate(vector<vector<int>>& matrix){
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = i + 1; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // to rotate the matrix anti-clockwisely:
    // fist, flip the matrix left to right;
    // finally, transpose the matrix
    void anticlockwise_rotate(vector<vector<int>>& matrix){
        for(auto row : matrix)  reverse(row.begin(), row.end());
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = i + 1; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // ************ fancy method 2 ************
    // first, transpose the matrix;
    // finally, reverse each row of the matrix.
    // reference: the 0ms solution in "accepted solutions runtime distribution" page.
    void rotate_method3(vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = i; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0, k = matrix.size() - 1; j < n / 2; ++j, --k){
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }

    // and similarly, (transpose+flip left-to-right) gets the anti-clockwise-rotated matrix.
};