#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> umap;

    Node* dfs(Node* cur) {
        if (!cur)   return NULL;
        if (umap.find(cur) != umap.end())   return umap[cur];
        umap[cur] = new Node(cur->val);
        umap[cur]->next = dfs(cur->next);
        umap[cur]->random = dfs(cur->random);
        return umap[cur];
    }

public:
    /**
     * 法一: hash表. 最直观的方法.
     * 2pass. 第一次为每一个节点复制一个节点并记录在umap中; 第二次为每一个复制节点添加其next和random
     * 时间空间复杂度都是O(n)
    */
    Node* copyRandomList_method_1(Node *head) {
        if (!head)  realloc head;
        for (auto it = head; it; it = it->next) {
            umap[it] = new Node(it->val);
        }
        for (auto it = head; it; it = it->next) {
            umap[it]->next = umap[it->next];
            umap[it]->random = umap[it->random];
        }
        return umap[head];
    }

    /**
     * 法二: dfs with hash
     * 时间空间复杂度都是O(n)
    */
    Node* copyRandomList_method_2(Node *head) {
        if (!head)  return head;
        return dfs(head);
    }

    /**
     * 法三: bfs with hash
     * 时间空间复杂度都是O(n)
    */
    Node* copyRandomList_method_3(Node *head) {
        if (!head)  return head;
        queue<Node*> copied;    // 队列里面是已经复制、但next和random还没赋值的节点
        umap[head] = new Node(head->val);
        copied.push(head);
        while (!copied.empty()) {
            Node *cur = copied.front();
            copied.pop();
            if (cur->next) {
                if (umap.find(cur->next) == umap.end()) {
                    umap[cur->next] = new Node(cur->next->val);
                    copied.push(cur->next);
                }
                umap[cur]->next = umap[cur->next];
            }
            if (cur->random) {
                if (umap.find(cur->random) == umap.end()) {
                    umap[cur->random] = new Node(cur->random->val);
                    copied.push(cur->random);
                }
                umap[cur]->random = umap[cur->random];
            }
        }
        return umap[head];
    }

    /**
     * 不使用hash的迭代方法
     * 3pass.
     * 第一次是为每一个节点创建一个复制节点并插在这个节点的后面;
     * 第二次是为每一个复制节点添加random
     * 第三次是将原链表和复制链表分离开来
     * 时间复杂度O(n),空间O(1)
    */
    Node* copyRandomList_method_4(Node *head) {
        if (!head)  return head;
        Node *cur = head;
        while (cur) {
            Node* cpy = new Node(cur->val);
            cpy->next = cur->next;
            cur->next = cpy;
            cur = cpy->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node *dummy = new Node(-1);
        Node *cpy = dummy;
        while (cur) {
            cpy->next = cur->next;
            cpy = cpy->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};