#include <iostream> // for key word "NULL"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *curr = head;
/*         while (curr->next) {
            if (curr->val == curr->next->val)   curr = curr->next;
            else {
                if (pre->next != curr)  pre->next = curr->next;
                else    pre = pre->next;
                curr = curr->next;
            }
        }
        if (pre->next != curr)  pre->next = curr->next; */

        // more concise and faster(8ms vs. 12ms) than the commented coded above.
        while (curr) {
            while (curr->next && curr->val == curr->next->val)  curr = curr->next;
            if (pre->next != curr)  pre->next = curr->next;
            else    pre = pre->next;
            curr = curr->next;
        }
        return dummy->next;
    }
private:
    ListNode* recursive_method(ListNode* head) {
        // reference:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/28335/My-accepted-Java-code
        if (!head || !head->next)   return head;
        if (head->next && head->val != head->next->val) {
            head->next = recursive_method(head->next);
            return head;
        }
        else {
            while(head->next && head->val == head->next->val)   head = head->next;
            return recursive_method(head->next);
        }
    }
};