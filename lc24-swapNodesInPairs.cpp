#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // it turns out that there is a case whose head is null
        if(head == NULL || head->next == NULL)  return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prior = head->next;
        ListNode* latter = dummy;
        while(prior != NULL){
            (latter->next)->next = prior->next;
            prior->next = latter->next;
            latter->next = prior;

            // this line of code is crucial for the following code
            prior = prior->next;

            if(prior->next != NULL){
                prior = (prior->next)->next;
                latter = (latter->next)->next;
            }
            else    break;
        }
        return dummy->next;
    }
};