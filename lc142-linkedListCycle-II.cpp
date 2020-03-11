#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // method 1: use <unordered_set>, O(n) space, trivial.
    ListNode *detectCycle(ListNode *head) {
        if (!head)  return head;
        unordered_set<ListNode*> uset;
        ListNode* cur = head;
        while (cur) {
            if (uset.find(cur) == uset.end()) {
                uset.insert(cur);
                cur = cur->next;
            }
            else {
                return cur;
            }
        }
        return NULL;
    }

    // method 2: fast & slow pointers. O(1) space.

    // notions:
    // L1: the distance between start node and entry node.
    // L2: the distance between entry node and meeting node (forward-wise direction).
    // r: the length of the cycle.
    // n: how many times fast pointer traveled around the cycle before they meet.

    // some basic conclusions:
    // slow pointer can travel around the cycle for once at most.
    // fast pointer travels around the cycle for once at least, i.e., n>=1.
    // the distance fast pointer travels is twice as the slow one does.

    // based on the information above:
    // the distance slow pointer covers is L1 + L2
    // the fast pointer covers is L1 + L2 + n*r
    // obviously, L1 + L2 + n*r = 2*(L1 + L2)
    // s.t., L1 + L2 = n*r ==> L1 = (n - 1)*r + (r - L2)
    // that implies that after meeting of fast & slow pointers,
    // let "entry" pointer (now at the start node) and slow pointer(now at the meeting node)
    // move forward together at the same speed, the node where they meet is the entry of the cycle.
    
    ListNode *method2(ListNode *head) {
        if (!head || !head->next)   return NULL;
        ListNode *slow = head, *fast = head, *entry = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};