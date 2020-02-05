#include <iostream>
#include <queue>
#include <algorithm>
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
// e need to add the smaller one of the child depths - except if 
// that's zero, then add the larger one.
    int minDepth(TreeNode* root) {
        // method 1: iteration, slow(16ms).
        if (!root)  return 0;
        int res = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int lastLevel = q.size();
            for (int i = 0; i < lastLevel; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (!temp->left && !temp->right)    return res;
                if (temp->left) q.push(temp->left);
                if (temp->right)    q.push(temp->right);
            }
            res++;
        }
        return res;

        // method 2: recursion, faster(8ms).
        if (!root)  return 0;
        else if (!root->left && !root->right)   return 1;
        else if (!root->left)   return 1 + minDepth(root->right);
        else if (!root->right)  return 1 + minDepth(root->left);
        else    return 1 + min(minDepth(root->left), minDepth(root->right));

        // method 3: a more concise recursion, but slower than method 2.(16ms)
        if (!root)  return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        return 1 + (left && right ? min(left, right) : max(left, right));
    }
};