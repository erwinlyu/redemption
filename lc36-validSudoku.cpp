#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
/*         set<char> blocks[3][3];
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
        return true; */

        // one set
        // seem to pass on VS 2019 compiler but leetcode runtime error
        set<string> exists;
        char int2char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char temp = board[i][j];
                if(temp == '.')  continue;
                if(exists.find(temp + "in row" + int2char[i]) != exists.end())    return false;
                else    exists.insert(temp + "in row" + int2char[i]);
                if(exists.find(temp + "in col" + int2char[j]) != exists.end())  return false;
                else    exists.insert(temp + "in col" + int2char[j]);
                if(exists.find(temp + "in block" + int2char[i / 3] + int2char[j / 3]) != exists.end())  return false;
                else    exists.insert(temp + "in block" + int2char[i / 3] + int2char[j / 3]);
            }
        }
        return true;
    }
};