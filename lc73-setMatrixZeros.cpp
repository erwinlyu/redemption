#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    /* space complexity O(m)+O(n).
        a trivial method: maintain two set which contains the number of row and col
        to be set to 0, respectively. */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> row0;
        set<int> col0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (row0.find(i) == row0.end())  row0.insert(i);
                    col0.insert(j);
                }
            }
        }
        for (set<int>::iterator it = row0.begin(); it != row0.end(); ++it) {
            for (int j = 0; j < n; ++j) matrix[*it][j] = 0;
        }
        for (set<int>::iterator it = col0.begin(); it != col0.end(); ++it) {
            for (int i = 0; i < m; ++i) matrix[i][*it] = 0;
        }
        return;
    }
    
    /* space complexity O(1)
        idea: if any element in a row is 0, make the first element of
        this row 0. the same process for columns.
        as for matrix[0][0], let it represent its row, and define an extra
        variable, bool col0, to denote whether the first column should be 0. */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col0 = false;

        // top-down
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0)  col0 = true;
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        // bottom-up
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0)   matrix[i][0] = 0;
        }
    }
};