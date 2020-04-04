#include <vector>
class Solution {
public:
    /**
     * 思路：
     * 矩阵有上下左右四个边界，分别是top, btm, lft and rgt.
     * 对于矩阵从外到内的每一层，分为“从左到右”、“从上到下”、“从右到左”和“从下到上”四个部分，
     * 对应于四个循环。每完成一个循环，都要将相应的边界收缩1， 
     * 并对边界条件(边界是否相遇)进行检查是否完成。
     * 
     * 本题与lc54相同，做法不同。这种做法思路清晰但运行速度相对较慢。
     * lc54运行较快但确定边界值比较繁琐。
    */
    std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix) {
        if (matrix.empty()) return std::vector<int>();
        int top = 0, btm = matrix.size() - 1, lft = 0, rgt = matrix[0].size() - 1;
        std::vector<int> res((btm + 1) * (rgt + 1));
        int idx = 0;
        while (true) {
            for (int i = lft; i <= rgt; ++i)    res[idx++] = matrix[top][i];
            if (++top > btm)    break;
            for (int i = top; i <= btm; ++i)    res[idx++] = matrix[i][rgt];
            if (--rgt < lft)    break;
            for (int i = rgt; i >= lft; --i)    res[idx++] = matrix[btm][i];
            if (--btm < top)    break;
            for (int i = btm; i >= top; --i)    res[idx++] = matrix[i][lft];
            if (++lft > rgt)    break;
        }
        return res;
    }
};