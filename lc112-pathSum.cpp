#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        helper(root, sum, 0);
        return equal;
    }
private:

    // method 1: my own recursion method.
    bool equal = false;
    void helper(TreeNode* root, int sum, int cur) {
        if (!root || equal) return;
        cur += root->val;
        if (!root->left && !root->right) {
            if (cur == sum) equal = true;
            return;
        }
        helper(root->left, sum, cur);
        helper(root->right, sum, cur);
    }

    // method 2: recursion method in submission page. concise, elegant, a little bit slower.
    bool haspathsum(TreeNode* root, int curSum) {
        if (!root)  return false;
        if (!root->left && !root->right)    return curSum == root->val;
        return haspathsum(root->left, curSum - root->val) || haspathsum(root->right, curSum - root->val);
    }
};