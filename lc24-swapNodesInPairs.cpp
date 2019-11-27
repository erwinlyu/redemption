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

        // method 1: two pointers
        // the fastest method
/*         
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
        return dummy->next; */

        // method 2: recursive way, a smart yet elusive algorithm
        // spent less memory yet runtime increased
        // reference: https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11030/My-accepted-java-code.-used-recursion.
        if(head == NULL || head->next == NULL)  return head;
        ListNode *ptr = head->next;
        head->next = swapPairs(head->next->next);
        ptr->next = head;
        return ptr;
    }
};