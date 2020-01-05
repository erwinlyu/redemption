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
    int maxDepth(TreeNode* root) {
        if (!root)  return depth;
        //dfs(root, depth);
        return findDepth(root, 0);
    }
private:
    int depth = 0;

    // my trivial method, not fast.
    void dfs(TreeNode *curr, int currDepth) {
        currDepth++;
        if (curr->left) dfs(curr->left, currDepth);
        if (curr->right)    dfs(curr->right, currDepth);
        else    depth = max(depth, currDepth);
        return;
    }

    // learnt from leetcode, a third faster than my own, same memory consuming.
    int findDepth(TreeNode* curr, int currDepth) {
        int left = curr->left == nullptr ? 0 : findDepth(curr->left, currDepth);
        int right = curr->right == nullptr ? 0 : findDepth(curr->right, currDepth);
        return 1 + max(left, right);
    }
};