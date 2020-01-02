#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        stack<TreeNode*> todo;
        while(!todo.empty() || root){
            if(root){
                todo.push(root);
                root = root->left;
            }
            else{
                root = todo.top();
                todo.pop();
                if(prev && prev->val >= root->val)   return false;
                prev = root;
                root = root->right;
            }
        }
        return true;
    }
};