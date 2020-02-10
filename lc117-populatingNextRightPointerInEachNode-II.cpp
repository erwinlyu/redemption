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

        // method 1: iterative way with queue.(8ms)
        if (!root)  return root;
        queue<Node*> nodesQ;
        nodesQ.push(root);
        while (!nodesQ.empty()) {
            int qsize = nodesQ.size();
            while (qsize > 0) {
                Node* cur = nodesQ.front();
                nodesQ.pop();
                if (cur->left)  nodesQ.push(cur->left);
                if (cur->right) nodesQ.push(cur->right);
                if (qsize > 1 && nodesQ.size() > 0)  cur->next = nodesQ.front();
                qsize--;
            }
        }
        return root;

        // method 2: iterative way WITHOUT queue.(16ms)
        if (!root)  return root;
        Node *pre = root, *dummy = new Node(), *cur = dummy;
        while (pre) {
            if (pre->left) {
                cur->next = pre->left;
                cur = cur->next;
            }
            if (pre->right) {
                cur->next = pre->right;
                cur = cur->next;
            }
            if (pre->next) pre = pre->next;
            else {
                pre = dummy->next;
                dummy->next = NULL;
                cur = dummy;
            }
        }
        return root;
    }
};