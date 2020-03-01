#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())  return;
        solve(board);
        return;
    }
private:
    bool solve(vector<vector<char>>& board) {
        /* backtracking without pruning. O(9^n), n is the number of blanks. */
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                for (char c = '1'; c <= '9'; ++c) { // try out the blank from '1' to '9'
                    if (isValid(board, i, j, c)) {  // if putting c in that blank is valid
                        board[i][j] = c;    // put c in that blank
                        if (solve(board))   return true;    // if it is the solution
                        else    board[i][j] = '.';  // otherwise withdraw to '.' in that blank
                    }
                }
                return false;   // if none of the 9 choices fits in, the path is not correct
            }
        }
        return true;    // if there is no '.' in the board, sududo has been solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] != '.' && board[row][i] == c) return false;
            if (board[i][col] != '.' && board[i][col] == c) return false;
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] != '.' &&
                board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == c)   return false;
        }
        return true;
    }
};