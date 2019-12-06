#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> blocks[3][3];
        set<char> rows[9];
        set<char> cols[9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char temp = board[i][j];
                if(temp == '.')  continue;
                if(rows[i].find(temp) != rows[i].end())  return false;
                else    rows[i].insert(temp);
                if(cols[j].find(temp) != cols[j].end()) return false;
                else    cols[j].insert(temp);
                if(blocks[i / 3][j / 3].find(temp) != blocks[i / 3][j / 3].end())   return false;
                else    blocks[i / 3][j / 3].insert(temp);
            }
        }
        return true;
    }
};