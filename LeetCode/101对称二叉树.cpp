/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool is_check(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;
    return is_check(p->left, q->right) && is_check(p->right, q->left);
}


bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return is_check(root->left, root->right);
}