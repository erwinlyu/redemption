#include <vector>
using namespace std;
class Solution {
    /* 由于本题矩阵是每一行从左到右递增,每一列从上到下递增,即并不保证i行的最后一个元素
       小于i+1行的第一个元素,因此强行二分不可取.
       强行二分的话只能从上到下逐行检查行首第一个元素与target的大小关系,小于target再
       二分搜索这一行.
       除非矩阵具有 行数不太多,列数超级多 的特点,否则强行二分的表现不好.
       
       正确的做法是从右上角的元素开始,如果它小于target那么往下走一行,如果大于target那么
       往左走一列,直到遇到target或走到左下角.
       这样可以获得O(m+n)的时间复杂度.
       该方法同样适用于从左下角开始走.
       
       评论区有人说站在右上角去看,这个矩阵就是一个binary search tree. */
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0) {
            if (matrix[row][col] < target)      row++;
            else if (matrix[row][col] > target) col--;
            else    return true;
        }
        return false;
    }
};