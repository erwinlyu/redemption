#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // method 1: iterative method
        int depth = findDepth(root);
        vector<vector<int>> res(depth, vector<int>());
        if (depth == 0) return res;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            vector<int> temp;
            int num = nodeQueue.size();
            for (int i = 0; i < num; ++i) {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                temp.push_back(cur->val);
                if (cur->left)  nodeQueue.push(cur->left);
                if (cur->right) nodeQueue.push(cur->right);
            }
            res[--depth] = temp;
        }
        return res;
    }
private:
    // get the depth of the tree to avoid reverse the final result.
    int findDepth(TreeNode* root) {
        if (!root)  return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }

    // method 2: recursive method
    void levelOrder(vector<vector<int>>& res, TreeNode* node, int level) {
        if (!node)  return;
        res[level].push_back(node->val);
        levelOrder(res, node->left, level - 1);
        levelOrder(res, node->right, level - 1);
    }
};