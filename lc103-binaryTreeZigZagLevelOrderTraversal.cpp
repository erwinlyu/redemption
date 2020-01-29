#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> myqueue;   //using <deque> is an alternative method
        if (root)   myqueue.push(root);
        else    return res;
        vector<int> level;
        bool odd = false;
        while (!myqueue.empty()) {
            int pre = myqueue.size();
            level.resize(pre);
            for (int i = 0; i < pre; ++i) {
                TreeNode* temp = myqueue.front();
                myqueue.pop();
                int idx = odd ? i : pre - 1 - i;    // avoid using reverse()
                level[idx] = temp->val;
                if (temp->left)     myqueue.push(temp->left);
                if (temp->right)    myqueue.push(temp->right);
            }
            res.push_back(level);
            odd = !odd;
        }
        return res;
    }
};