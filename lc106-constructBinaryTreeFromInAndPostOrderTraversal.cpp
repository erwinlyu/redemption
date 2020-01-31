#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        for (int i = 0; i < len; ++i)   ump[inorder[i]] = i;
        idx_of_in = len - 1;
        idx_of_post = len - 1;
        return aux_func(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
private:
    unordered_map<int, int> ump;
    // using map can significantly speed up the program,
    // compared to search idx one by one (12ms vs. 20ms),
    // and it takes a little more space.
    TreeNode* aux_func(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postR) {
        if (inL > inR || postR < 0) return NULL;
        int idx = ump[postorder[postR]];
        //while (inorder[idx] != postorder[postR])    idx++;    search idx one by one
        TreeNode* root = new TreeNode(postorder[postR]);
        root->left = aux_func(inorder, postorder, inL, idx - 1, postR - inR + idx - 1);
        root->right = aux_func(inorder, postorder, idx + 1, inR, postR - 1);
        return root;
    }

// hard to understand
//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/34782/My-recursive-Java-code-with-O(n)-time-and-O(n)-space
    int idx_of_in;  // index of inorder array
    int idx_of_post;    // index of postorder array
    TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder, TreeNode* end) {
        // treenode end is the boundary of the left subtree
        if (idx_of_post < 0)    return NULL;
        TreeNode* root = new TreeNode(postorder[idx_of_post--]);
        // go all the way down to the right-est node of the right subtree
        // if right node exists, create right subtree
        if (inorder[idx_of_in] != root->val)
            root->right = buildHelper(inorder, postorder, root);
        
        // idx_of_in sustains until the recursion meets the right-est node
        idx_of_in--;

        // if left node exists, create left subtree
        if (end == NULL || inorder[idx_of_in] != end->val)
            root->left = buildHelper(inorder, postorder, end);
        return root;
    }
};