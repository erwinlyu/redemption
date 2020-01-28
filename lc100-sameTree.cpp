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
    // real recursion (√)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (!p || !q)  return false;
        if (p->val != q->val)   return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        //inOrder(p, q);
        //return same;
    }
private:
    bool same = true;
    // fake recursion (×) by my own...
    void inOrder(TreeNode* p, TreeNode* q) {
        if (!same)  return;
        if (p && q) {
            if (p->val != q->val) {
                same = false;
                return;
            }
            inOrder(p->left, q->left);
            inOrder(p->right, q->right);
        }
        else if (!p && !q)  return;
        else {
            same = false;
            return;
        }
    }
};