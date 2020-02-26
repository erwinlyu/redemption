#include <vector>
using namespace std;
class Solution {
public:
    // brute simulation(dfs).
    void solve(vector<vector<char>>& board) {
        if (board.empty())  return;
        height = board.size();
        width = board[0].size();
        for (int i = 0; i < height; ++i) {
            if (board[i][0] == 'O') markConnect(board, i, 0);
            if (board[i][width - 1] == 'O') markConnect(board, i, width - 1);
        }
        for (int j = 0; j < width; ++j) {
            if (board[0][j] == 'O') markConnect(board, 0, j);
            if (board[height - 1][j] == 'O')    markConnect(board, height - 1, j);
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else    board[i][j] = 'X';
            }
        }
    }
private:
    int height, width;
    void markConnect(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= height)   return;
        if (col < 0 || col >= width)    return;
        if (board[row][col] == 'O') {
            board[row][col] = '#';
            markConnect(board, row - 1, col);
            markConnect(board, row + 1, col);
            markConnect(board, row, col - 1);
            markConnect(board, row, col + 1);
        }
    }
};