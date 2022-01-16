/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    return searchBST(val > root->val ? root->right : root->left, val);
}