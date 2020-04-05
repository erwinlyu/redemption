#include <vector>
#include <stack>
class Solution {
public:
    /**
     * 方法一：递归,略. 时间复杂度O(n^2), 空间复杂度O(N)
     * 方法二：非递归: 辅助单调栈
     * 思想: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
    */
    bool verifyPostorder(std::vector<int>& postorder) {
        std::stack<int> mono_inc_stk;
        int root = INT_MAX;
        mono_inc_stk.push(root);    // "mono_inc_stk" stands for "monotonically increasing stack"
        int n = postorder.size();
        for (int i = n - 1; i >= 0; --i) {  // 后序遍历的倒序
            if (postorder[i] > root)    return false;   // 如果所观察的节点值大于当前root值,那么不满足bst后序遍历性质
            while (!mono_inc_stk.empty() && mono_inc_stk.top() > postorder[i]) {    // 所观察的节点值的父节点应该是栈中大于它且最接近它的那一个,成为新的root值
                root = mono_inc_stk.top();
                mono_inc_stk.pop();
            }
            mono_inc_stk.push(postorder[i]);    // 所观察的节点值入栈
        }
        return true;    // 如果流程能够走完,说明是合法的bst后序遍历
    }
};