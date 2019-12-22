#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL)  return head;
        int nodeNum = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy, *q = dummy;
        while(nodeNum < k){
            if(q->next == NULL){
                k %= nodeNum;
                if(k == 0)  return dummy->next;
                nodeNum = 0;
                q = dummy;
                continue;
            }
            q = q->next;
            ++nodeNum;
        }
        while(q->next){
            p = p->next;
            q = q->next;
        }
        if(p == dummy)  return dummy->next; // in case k == # of nodes
        dummy->next = p->next;
        q->next = head;
        p->next = NULL;
        return dummy->next;
    }
};