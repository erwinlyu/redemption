#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre(1, 1), cur;
        for (int i = 1; i <= rowIndex; ++i) {
            cur.resize(i + 1);
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)    cur[j] = 1;
                else    cur[j] = pre[j - 1] + pre[j];
            }
            pre = cur;
        }
        return pre;
    }

    // method 2: dp solution, O(n).
    // ref:https://leetcode.com/problems/pascals-triangle-ii/discuss/38420/Here-is-my-brief-O(k)-solution
    vector<int> dp(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int row = 0; row < rowIndex; ++row)
            for (int col = row; col > 0; --col)
                res[col] += res[col - 1];
        return res;
    }
};