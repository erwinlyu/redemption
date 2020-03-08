#include <unordered_map>
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    // method 1: my own 2-pass, O(N) space method.
    Node* copyRandomList(Node* head) {
        if (!head)  return head;
        Node* cur = head;
        while (cur) {
            Node* copy_of_cur = new Node(cur->val);
            umap[cur] = copy_of_cur;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            umap[cur]->next = umap[cur->next];
            umap[cur]->random = umap[cur->random];
            cur = cur->next;
        }
        return umap[head];
    }

    // method 2: 3-pass, O(1) space
    // ref: https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)
    Node* constant_space_method(Node* head) {
        if (!head)  return head;
        Node* cur = head;
        while (cur) {
            Node* copy_of_cur = new Node(cur->val);
            copy_of_cur->next = cur->next;
            cur->next = copy_of_cur;
            cur = copy_of_cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node* pseudo_head = new Node(-1);
        Node* copy = pseudo_head;
        while (cur) {
            copy->next = cur->next;
            copy = copy->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return pseudo_head->next;
    }

private:
    unordered_map<Node*, Node*> umap;
};