/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) return cloned;
        if (cloned == NULL || original == NULL) return NULL;
        TreeNode *ans = NULL, *left = NULL, *right = NULL;
        if (original->left) ans = getTargetCopy(original->left, cloned->left, target);
        if (ans == NULL && original->right) return getTargetCopy(original->right, cloned->right, target);
        return ans;
    }
};