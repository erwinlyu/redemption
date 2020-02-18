#include <vector>
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
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
        // iterative ways, like dfs+stack and bfs+queue are also options.
    }
private:
    // recursive dfs
    int sum(TreeNode* root, int accu) {
        if (!root)  return 0;
        int cur = 10 * accu + root->val;
        if (!root->left && !root->right)    return cur;
        return sum(root->left, cur) + sum(root->right, cur);
    }
};