#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return genTree(1, n);
    }
private:
    // the recursive function need to construct the vectors of roots of each level
    // and trees at the same time.
    // https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31494/A-simple-recursive-solution
    vector<TreeNode*> genTree(int start, int end) {
        vector<TreeNode*> rootsBylevel;
        if (start > end) {
            rootsBylevel.push_back(NULL);
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTrees = genTree(start, i - 1);
            vector<TreeNode*> rightTrees = genTree(i + 1, end);
            for (TreeNode* leftRoot : leftTrees) {
                for (TreeNode* rightRoot : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    rootsBylevel.push_back(root);
                }
            }
        }
        return rootsBylevel;
    }
};
int main() {
    Solution sln;
    vector<TreeNode*> res = sln.generateTrees(3);
    cout << res.size() << endl;
    for (TreeNode* item : res)  cout << item->val << " ";
    return 0;
}