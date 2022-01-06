/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void pre_order(struct TreeNode *root, int *res, int *returnSize) {
    if (root == NULL) return ;
    res[(*returnSize)++] = root->val;
    pre_order(root->left, res, returnSize);
    pre_order(root->right, res, returnSize);
    return ;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 505);
    *returnSize = 0;
    pre_order(root, res, res, returnSize);
    return res;
}