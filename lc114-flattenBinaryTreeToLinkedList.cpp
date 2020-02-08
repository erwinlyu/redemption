#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    // method 3: the optimal recursive method.
    // ref: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
    // use pre to record the root of left subtree which need to insert to the right
    // position of current root node.
    // this method avoids locating the rightmost node of a left subtree process
    // in method 1, thus saves running time. (4ms vs. 8ms)
    void flatten(TreeNode* root) {
        if (!root)  return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }

private:
    TreeNode* pre = NULL;   // used in method 3.

    // method 1: my own recursive method.
    // recursively flatten left subtree and right subtree
    // then transplant the left subtree between the root and right subtree.
    void recursion (TreeNode* root) {
        if (!root)  return;
        recursion(root->left);
        recursion(root->right);
        if (!root->left)    return;
        transplant(root);
    }

    // method 2: my own iterative method. no stack needed.
    // begin with the input root node, always transplant the left subtree
    // between the root and root's right subtree. then walk to the right
    // node and repeat the process.
    // time is O(n), space is O(1).
    void iteration (TreeNode* root) {
        transplant(root);
        root = root->right;
    }

    void transplant(TreeNode* root) {
        // auxiliary function for method 1 and 2.
        // find the rightmost node in the left subtree, and splice the right subtree
        // to the right of this node.
        if (!root || !root->left)  return;
        TreeNode* rightmost = root->left;
        while (rightmost->right)    rightmost = rightmost->right;
        rightmost->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};