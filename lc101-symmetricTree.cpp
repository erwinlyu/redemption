#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // recursive method is faster and less memory consuming.
        if (root == nullptr) return true;
        //return recursivelyCheck(root->left, root->right);
        return iterativelyCheck(root);
    }

private:
    // reference: https://leetcode.com/problems/symmetric-tree/discuss/33104/1ms-recursive-Java-Solution-easy-to-understand
    bool recursivelyCheck(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left->val == right->val
                && recursivelyCheck(left->left, right->right)
                && recursivelyCheck(left->right, right->left));
    }

    bool iterativelyCheck(TreeNode *root){
        if(!root)   return false;
        queue<TreeNode*> check;
        check.push(root->left);
        check.push(root->right);
        while (!check.empty()) {
            TreeNode *p = check.front();
            check.pop();
            TreeNode *q = check.front();
            check.pop();

            // use XOR instead of 
            //if(!q && p) return false; if(!p && q) return false; 
            // to speed up.
            if (!p ^ !q) return false;

            if (p && q) {
                if (p->val != q->val)    return false;
                check.push(p->left);
                check.push(q->right);
                check.push(p->right);
                check.push(q->left);
            }
        }
        return true;
    }
};