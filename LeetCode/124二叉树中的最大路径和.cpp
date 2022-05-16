/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int backtracking(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = max(backtracking(root->left), 0);
        int right = max(backtracking(root->right), 0);
        int temp = left + right + root->val;
        ans = max(ans, temp);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        backtracking(root);
        return ans;
    }

private :
    int ans = INT_MIN;
};