 Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // the plain method, lack of goodness
/*         if(l1 == NULL && l2 == NULL)    return NULL;
        ListNode *dummy = new ListNode(-1);
        ListNode *l3 = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                ListNode *temp = new ListNode(l1->val);
                l3->next = temp;
                l3 = l3->next;
                l1 = l1->next;
            }
            else{
                ListNode *temp = new ListNode(l2->val);
                l3->next = temp;
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        if(l1 != NULL)  l3->next = l1;
        else l3->next = l2;
        return dummy->next; */

        // the samrt recursion method
        // key idea is: always return the smaller one between l1 and
        // l2, until one of the two lists is empty
        // in this way, an additional list l3 is no longer needed.
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

        // the performance of both methods is basically the same
    }
};