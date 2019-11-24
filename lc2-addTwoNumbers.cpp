 #include <iostream>
 using namespace std;
 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //initialize with null otherwise time out
        ListNode* l3head = NULL;
        ListNode* l3tail = NULL;
        bool carry = false;
        while(l1 != NULL || l2 != NULL || carry){
            int temp = 0;
            if(carry){
                temp++;
                carry = false;
            }
            if(l1 != NULL){
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                temp += l2->val;
                l2 = l2->next;
            }
            if(temp > 9){
                temp -= 10;
                carry = true;
            }
            else    carry = false;
            if(l3head == NULL){
                l3tail = l3head = new ListNode(temp);
            }
            else{
                //ListNode* p = new ListNode(temp)
                //l3tail->next = p
                //is slower
                l3tail->next = new ListNode(temp);
                l3tail = l3tail->next;
            }
        }
        return l3head;
    }
};