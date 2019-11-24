#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

/* the first version of two pointers, one points to the node before, the other points to head
        // to deal with case like [1],1
        if(head->next == NULL){
            if(n == 1)  return NULL;
            else    return head;
        }
        ListNode *p = head;
        ListNode *prev = new ListNode(-1);
        prev->next = head;
        int cnt = 0;
        while(cnt < n){
            if(p != NULL){
                p = p->next;
                cnt++;
            }
            else    return head;
        }
        while(p != NULL){
            p = p->next;
            prev = prev->next;
        }

        // to deal with the cases whose n equals the length of the linked list
        if(prev->val == -1) head = head->next;
        else    prev->next = (prev->next)->next;
        return head; */

// the second version of two pointers, 
// both of them point to the dummy node before head, which is clearer
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        for(int i = 0; i <= n; i++){
            first = first->next;
        }
        while(first != NULL){
            first = first->next;
            second = second->next;
        }
        second->next = (second->next)->next;

        // here, return dummy->next instead of returning directly head itself, is crucial
        // this could handle the case like [1,2],2
        return dummy->next;
    }
};
int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = new ListNode(2);
    head->next = temp;
    Solution sln;
    ListNode *output = sln.removeNthFromEnd(head, 2);
    cout << output->val;
    return 0;
}