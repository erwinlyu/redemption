#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // method 1: merge lists one by one.
        // time complexity O(kN) if k is the number of lists' nodes.
        if (lists.empty())  return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            dummy->next = merge2lists(dummy->next, lists[i]);
        }
        return dummy->next;

        // method 2: merge with divide and conquer. optimized version of method 1.
        // ref: solution page of this problem.
        // every round merge the lists by pair into a k/2 lists.
        // time complexity O(N*lg(k)).

        // comparison to method1:
        //  - pros: much faster than method 1 (28ms vs.250+ms in 131 cases).
        //  - cons: does not preserve the original lists.
        if (lists.empty())  return NULL;
        int amount = lists.size(), interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2) {
                lists[i] = merge2lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];

        // method 3: compare one by one with priority queue.
        // similar performance to method 2.
        // ref:https://leetcode.com/problems/merge-k-sorted-lists/discuss/10527/Difference-between-Priority-Queue-and-Heap-and-C%2B%2B-implementation
        priority_queue<ListNode*, vector<ListNode*>, usrCmp> pq;
        for (ListNode* node : lists) {
            if (node)   pq.push(node);
        }
        if (pq.empty()) return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next)    pq.push(top->next);
        }
        return dummy->next;

        // method 4: compare one by one with heap.
        vector<ListNode*> v;
        for (auto node : lists) {
            if (node)   v.push_back(node);
        }
        make_heap(v.begin(), v.end(), heapCmp);
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!v.empty()) {
            cur->next = v.front();
            pop_heap(v.begin(), v.end(), heapCmp);
            v.pop_back();
            cur = cur->next;
            if (cur->next) {
                v.push_back(cur->next);
                push_heap(v.begin(), v.end(), heapCmp);
            }
        }
        return dummy->next;
    }
private:
    struct usrCmp { // priority queue的自构建比较函数,从小到大排列
        bool operator() (const ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        }
    };

    static bool heapCmp(ListNode* node1, ListNode* node2) {
        // heap的比较函数，小顶堆
        return node1->val > node2->val;
    }

    ListNode* merge2lists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = merge2lists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge2lists(l1, l2->next);
            return l2;
        }
    }
};