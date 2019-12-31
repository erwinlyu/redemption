#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        
        // method 1: iterative solution.
        while(!s.empty() || root){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }

        // another similar way to implement iterative solution. difference is inferior.
        // nearly the same time & space performance.
        while(!s.empty() || root){
            while (root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        
        //recursiveInorderTraversal(root);  // recursive method
        
        return res;
    }

private:
    vector<int> res;

    // method 2: recursive solution.
    // a little bit faster than its iterative counterpart and consumes a little more memory.
    void recursiveInorderTraversal(TreeNode* root){
        if(!root)   return ;
        recursiveInorderTraversal(root->left);
        res.push_back(root->val);
        recursiveInorderTraversal(root->right);
    }

    // method 3: Morris traversal algorithm.
    // the Morris traversal works dependantly on threaded-binary-tree.
    // reference: https://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion
    // advantage: O(n) time complexity and constant space complexity, whereas 
    // the other traversal method are O(n)-space-complexity. 
    void morrisTraversal(TreeNode* root){
        if(!root)   return ;
        TreeNode *curr = root, *pre;
        while(curr){
            if(!curr->left){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                pre = curr->left;
                while(pre->right && pre->right != curr) pre = pre->right;
                if(!pre->right){
                    pre->right = curr;
                    curr = curr->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
};