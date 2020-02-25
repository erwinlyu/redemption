#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        auxfunc(root);
        return res;
    }
private:

    // 该题可以看作 最大子序列和问题(e.g. lc53, lc121) 的变种.
    // 传统的最大子序列和的dp状态转移方程为 dp[i] = max(0, dp[i-1]) + arr[i],
    // 其简化形式为 cur = max(0, cur) + arr[i].
    // 与之类比,在该问题中,将传递上来的root的左子树和右子树的返回值中较大的一个看作是上式的max(0, cur),
    // 接着与该root的val相加,即加上了arr[i],作为返回值传递上去.
    // 在return之前,还要更新全局最大值res,它等于联通路径,即左子树-root-右子树,的最大和.
    int res = INT_MIN;
    int auxfunc(TreeNode* root) {
        if (!root)  return 0;
        int l_val = max(0, auxfunc(root->left));
        int r_val = max(0, auxfunc(root->right));
        res = max(res, l_val + r_val + root->val);
        return max(l_val, r_val) + root->val;
    }

    // 一种错误思路：对树做中序遍历得到每个节点的val构成的数组nums，接着dp求nums的最大子序列和.
    // 反例：[1,-2,-3,1,3,-2,null,-1](层序).
    // 出错的地方在于，该树的中序遍历结果[-1,1,-2,3,1,-2,-3]中3和1虽然相邻，但在树中，
    // 3是root的左子树的最右节点,而1是root节点,中间隔着-2,并不符合题意描述的连接方式.
    int cur_sum = INT_MIN, max_sum = INT_MIN;
    void inorder(TreeNode* root) {
        if (!root)  return;
        inorder(root->left);
        cur_sum = max(0, cur_sum) + root->val;
        max_sum = max(max_sum, cur_sum);
        inorder(root->right);
    }
};
int main() {
    TreeNode *root = new TreeNode(-10);
    TreeNode *node1 = new TreeNode(9);
    root->left = node1;
    TreeNode *node2 = new TreeNode(20);
    root->right = node2;
    TreeNode *node3 = new TreeNode(15);
    node2->left = node3;
    TreeNode *node4 = new TreeNode(7);
    node2->right = node4;
    Solution sln;
    printf("%d\n", sln.maxPathSum(root));
    return 0;
}