#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return aux_func(preorder, inorder, 0, 0, inorder.size() - 1);
    }
private:
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map
    // first I decided to construct a recursive function with 6 parameter:
        //preorder, inorder, preL, preR, inL, inR
    // infact the parameter preR is not only non-essential but also made me stuck in
    // juding the corner cases.
    TreeNode* aux_func(vector<int>& preorder, vector<int>& inorder, int preL, int inL, int inR) {
        if (preL > preorder.size() - 1 || inL > inR)    return NULL;
        TreeNode* root = new TreeNode(preorder[preL]);
        int idx = inL;
        while (inorder[idx] != preorder[preL])  idx++;
        root->left = aux_func(preorder, inorder, preL + 1, inL, idx - 1);
        root->right = aux_func(preorder, inorder, preL + idx - inL + 1, idx + 1, inR);
        return root;
    }
};