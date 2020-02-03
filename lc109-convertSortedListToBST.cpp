#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ptr = head;
        // get the number of nodes first.
        int cnt = 0;
        while (ptr) {
            cnt++;
            ptr = ptr->next;
        }
        ptr = head;
        return helper(0, cnt - 1);
    }
private:
    // method 1: convert to an array + lc108 recursion. a trivial method.

    // method 2: inorder simulation. (same performance as method 1).
    // ref: leetcode solution page of this problem.
    ListNode* ptr;
    TreeNode* helper(int start, int end) {
        if (start > end)    return NULL;

        // find the position of the root node.
        int mid = start + (end - start) / 2;

        // construct left subtree first.
        TreeNode* left = helper(start, mid - 1);

        // construct root node after left half is traversed.
        TreeNode* root = new TreeNode(ptr->val);
        root->left = left;
        ptr = ptr->next;

        // recurse the right half.
        root->right = helper(mid + 1, end);
        return root;
    }
};