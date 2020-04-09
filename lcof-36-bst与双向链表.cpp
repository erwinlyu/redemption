#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * 解题思路:
 * 本题的本质就是bst的中序遍历. 无论是递归、带辅助栈的迭代还是Morris中序遍历,
 * 要做的就是把普通的中序遍历中打印节点val改成将两个相邻的节点连接在一起,
 * 全部节点都两两连接后bst也就变成了双向链表了,最后再把首尾两端连接起来.
*/
class Solution {
private:
    Node *fake_head = new Node(-1), *prev = fake_head;

    Node* dfs(Node *cur) {
        if (!cur)   return cur;
        dfs(cur->left);
        prev->right = cur;
        cur->left = prev;
        prev = prev->right;
        dfs(cur->right);
        return cur;
    }

public:
    // method 1: 递归
    Node* treeToDoublyList(Node* root) {
        if (!root)  return root;
        dfs(root);
        fake_head = fake_head->right;
        fake_head->left = prev;
        prev->right = fake_head;
        return fake_head;
    }

    // method 2: Morris中序遍历
    Node* morris_inorder(Node* root) {
        if (!root)  return root;
        Node *cur = root, *pre = root, *fake_head = new Node(-1), *last = fake_head;
        /* Morris中序遍历将所有bst节点按照中序遍历的顺序前后连接起来 */
        while (cur) {
            if (!cur->left) {
                // last和cur是bst的中序顺序中相邻的两个节点,将他们连接起来
                last->right = cur;
                cur->left = last;

                last = last->right;
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    // last和cur是bst的中序顺序中相邻的两个节点,将他们连接起来
                    last->right = cur;
                    cur->left = last;

                    last = last->right;
                    cur = cur->right;
                }
            }
        }

        /* 接下来只需要将链表的首端和尾端连接起来 */
        while (pre->right)  pre = pre->right;
        cur = fake_head->right;
        pre->right = cur;
        cur->left = pre;
        return fake_head->right;
    }
};

int main() {
    Node *root = new Node(4);
    Node *node1 = new Node(2);
    root->left = node1;
    Node *node2 = new Node(5);
    root->right = node2;
    Node *node3 = new Node(1);
    node1->left = node3;
    Node *node4 = new Node(3);
    node1->right = node4;
    Solution sln;
    Node *res = sln.treeToDoublyList(root);
    for (int i = 0; i < 10; ++i) {
        cout << res->val << endl;
        res = res->left;
    }
    return 0;
}