#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return res;
        todo.push(root);
        while (!todo.empty()) {
            int cnt = todo.size();
            vector<int> temp;
            while (cnt--) {
                TreeNode *curr = todo.front();
                todo.pop();
                temp.push_back(curr->val);
                if (curr->left) todo.push(curr->left);
                if (curr->right)    todo.push(curr->right);
            }
            res.push_back(temp);
        }
        
        //bfs(vector<TreeNode*>(1, root));  // faster but consumes more memory.
        return res;
    }
private:
    vector<vector<int>> res;
    queue<TreeNode*> todo;

    void bfs(vector<TreeNode*> level){
        vector<int> temp;
        vector<TreeNode*> nextLevel;
        for (TreeNode *node : level) {
            temp.push_back(node->val);
            if (node->left) nextLevel.push_back(node->left);
            if (node->right)    nextLevel.push_back(node->right);
        }
        if (!temp.empty())  res.push_back(temp);
        if (!nextLevel.empty()) bfs(nextLevel);
    }
};