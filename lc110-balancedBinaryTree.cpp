#include <iostream>
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
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
private:
    int getDepth(TreeNode* root) {
        if (!root)  return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
            return -1;
        return 1 + max(leftDepth, rightDepth);
    }
};