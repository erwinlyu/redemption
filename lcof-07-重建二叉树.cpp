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

// 递归和迭代地通过前序+中序遍历数组重建二叉树
// 二者都是O(n)time O(n)space
// 不过最终结果迭代比递归快,且内存消耗更小
class Solution {
public:
    TreeNode* iteration(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())   return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);
        int in_idx = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int pre_val = preorder[i];
            TreeNode* cur = s.top();

            // 如果栈顶node的val不等于当前的inorder的val,那么说明栈顶node仍有左子树
            if (cur->val != inorder[in_idx]) {
                cur->left = new TreeNode(pre_val);
                s.push(cur->left);
            }

            // 如果不等于,那么要顺着刚刚构建左子树的路径回溯,找到有右子树待插入的那个root
            else {
                while (!s.empty() && s.top()->val == inorder[in_idx]) {
                    cur = s.top();
                    s.pop();
                    in_idx++;
                }
                cur->right = new TreeNode(pre_val);
                s.push(cur->right);
            }
        }
        return root;
    }

    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder) {
        return recursion_aux(preorder, inorder, 0, 0, inorder.size());
    }
private:
    TreeNode* recursion_aux(vector<int>& preorder, vector<int>& inorder, int pre_root, int in_l, int in_r) {
        // 在递归的过程中,pre_root只有一直增大,不会减小,所以无需pre_root>=0
        if (pre_root > preorder.size() - 1 || in_l > in_r)   return NULL;

        TreeNode* root = new TreeNode(preorder[pre_root]);

        // 将idx定位到root的val在inorder中的位置,这样就可以获得左右子树各有多少个节点
        // 这一过程也可以通过事先把inorder映射到hash表中来直接获取root的索引
        int idx = in_l;
        while (inorder[idx] != preorder[pre_root])  idx++;

        root->left = recursion_aux(preorder, inorder, pre_root + 1, in_l, idx - 1);
        root->right = recursion_aux(preorder, inorder, pre_root + (idx - in_l + 1), idx + 1, in_r);
        return root;
    }
};