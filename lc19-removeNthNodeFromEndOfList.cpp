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
        return head;
    }
};
int main(){
    ListNode *head = new ListNode(1);
    Solution sln;
    ListNode *output = sln.removeNthFromEnd(head, 1);
    cout << output->val;
    return 0;
}