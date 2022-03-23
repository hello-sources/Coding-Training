/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool judge(struct TreeNode *root, struct TreeNode *subRoot) {
    if (!root && !subRoot) return true;
    if ((root && !subRoot) || (!root && subRoot) || (root->val != subRoot->val)) return false;
    return judge(root->left, subRoot->left) && judge(root->right, subRoot->right);
}

bool order(struct TreeNode *root, struct TreeNode *subRoot) {
    if (!root) return false;
    return judge(root, subRoot) || order(root->left, subRoot) || order(root->right, subRoot);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    return order(root, subRoot);
}