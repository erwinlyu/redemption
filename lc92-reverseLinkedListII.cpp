#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // method 1: iteration
        if (!head || !head->next || m == n)   return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* front = dummy;
        for (int i = 1; i < m; ++i) front = front->next;
        ListNode *last = dummy;
        for (int i = 0; i < n; ++i) last = last->next;
        while (front->next != last) {
            ListNode* first = front->next;
            front->next = first->next;
            first->next = last->next;
            last->next = first;
        }
        return dummy->next;
    }
private:
    // method 2: recursion  (poor performance)
    ListNode* lo;
    bool crossed = false;
    void backtracking(ListNode* hi, int m, int n) {
        // when hi pointer meets its designated spot, n.
        if (n == 1) return;

        // else hi pointer keeps moving forward.
        else    hi = hi->next;

        // keep moving lo pointer forward until meets its designated spot, m.
        if (m > 1)  lo = lo->next;

        backtracking(hi, m - 1, n - 1);

        // if lo and hi pointers crossed, stop swapping.
        if (lo == hi || hi->next == lo) crossed = true;

        // if lo and hi are not crossed, swap their vals.
        if (!crossed) {     // swap the value of lo and hi pointers.
            int temp = lo->val;
            lo->val = hi->val;
            hi->val = lo->val;

            // move lo forward after swapping.
            // the hi pointer moves one step backward via the unfold of recursion.
            lo = lo->next;
        }
    }
};