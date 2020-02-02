#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL);
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return a2bst_helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* a2bst_helper(vector<int>& nums, int start, int end) {
        if (start > end)    return NULL;
        int mid = start + (end - start) / 2 + 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = a2bst_helper(nums, start, mid - 1);
        root->right = a2bst_helper(nums, mid + 1, end);
        return root;
    }
};