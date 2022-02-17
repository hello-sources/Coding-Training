/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool calc(struct TreeNode *root, int val) {
    if (root == NULL) return true;
    if (val != root->val) return false;
    return calc(root->left, val) && calc(root->right, val);
}

bool isUnivalTree(struct TreeNode* root){
    return calc(root, root->val);
}