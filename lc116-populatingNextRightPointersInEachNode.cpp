#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // method 1: iteration WITH <queue>.
        if (!root)  return root;
        queue<Node*> nodesQ;
        nodesQ.push(root);
        while (!nodesQ.empty()) {
            int qsize = nodesQ.size();
            Node* pre = nodesQ.front();
            nodesQ.pop();
            if (pre->left)  {
                nodesQ.push(pre->left);
                nodesQ.push(pre->right);
            }
            while (qsize > 1) {
                Node* cur = nodesQ.front();
                nodesQ.pop();
                if (cur->left) {
                    nodesQ.push(cur->left);
                    nodesQ.push(cur->right);
                }
                pre->next = cur;
                pre = cur;
                qsize--;
            }
        }
        return root;

        // method 2: iteration WITHOUT <queue>.
        // a little bit faster (20ms vs. 24ms) than method 1 and almost same memory.
        if (!root)  return root;
        Node* parent = root;
        Node* leftmost = root->left;
        int numOfLevel = 1;
        while (leftmost) {
            Node* child = leftmost;
            for (int i = 0; i < numOfLevel; ++i) {
                child->next = parent->right;
                child = child->next;
                if (parent->next) {
                    parent = parent->next;
                    child->next = parent->left;
                    child = child->next;
                }
            }
            numOfLevel *= 2;
            parent = leftmost;
            leftmost = leftmost->left;
        }
        return root;

        // method 2: recursion.
        // ref:https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37503/C%2B%2B-IterativeRecursive
        // similar performance to method 1.
        if (!root)  return root;
        if (root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};