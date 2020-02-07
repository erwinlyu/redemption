#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, path, sum);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode* root, vector<int>& path, int sum) {
        if (!root)  return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val) res.push_back(path);
        }
        dfs(root->left, path, sum - root->val);
        dfs(root->right, path, sum - root->val);
        path.pop_back();
    }
};