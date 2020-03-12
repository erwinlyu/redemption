#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    // method 1: use <deque>, trivial.

    // method 2: 3 steps, O(1) space.
    void reorderList(ListNode* head) {
        if (!head || !head->next)   return;

        // step 1: find the middle node of the list.
        ListNode *p1 = head, *p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // step 2: reverset the hafl list after the middle node.
        ListNode *mid = p1;
        p1 = p1->next;
        while (p1->next) {
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = mid->next;
            mid->next = p2;
        }

        // step 3: insert each node of the right half into right place one by one.
        p1 = head;
        p2 = mid->next;
        while (p1 != mid) {
            mid->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
            p2 = mid->next;
        }
    }
};