#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
// reference: https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = new ListNode(-1);
        ListNode *secon = new ListNode(-1);
        ListNode *cur1 = first, *cur2 = secon;
        while (head) {
            if (head->val < x)          cur1 = cur1->next = head;
            else if (head->val >= x)    cur2 = cur2->next = head;
            head = head->next;
        }
        cur2->next = NULL;
        cur1->next = secon->next;
        return first->next;
    }
};