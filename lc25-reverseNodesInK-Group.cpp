#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // my own iterative version. bad.
/*      ListNode *dummy = new ListNode(-1);   
        dummy->next = head;
        ListNode *left = dummy, *right = dummy;
        while (left->next) {
            ListNode *pre = left, *cur = left;
            for (int i = 0; i < k; ++i) {
                if (cur->next)  cur = cur->next;
                else {
                    left = NULL;
                    break;
                }
            }
            if (!left)  break;
            right = cur->next;
            ListNode *temp = cur;
            while (cur != left->next) {
                pre = left;
                while (pre->next != cur)    pre = pre->next;
                cur->next = pre;
                cur = cur->next;
            }
            cur->next = right;
            left->next = temp;
            for (int i = 0; i < k; ++i) left = left->next;
        }
        return dummy->next; */
        
        // 反转链表的正确姿势.
        // ref:https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11543/C%2B%2B-iterative
        int len = lenOf(head);
        dummy->next = head;
        for (int round = 0; round < len / k; ++round) {
            for (int i = 1; i < k; ++i) {
            // extract and move the node after head to the next of pre for k-1 times.
                ListNode *temp = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = temp;
            }
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }
private:
    // use local dummy node instead of using heap allocated node, 2 reasons:
    // 1) Once you use keyword new , then you have to delete the instance. Otherwise, 
    //      it's memory leak.
    // 2) Dummy node give you a very clear expectation about the lifetime of an object. 
    //      And also stack allocation is generally faster than heap allocation in c++.
    ListNode *dummy = new ListNode(-1), *pre = dummy;

    int lenOf(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};