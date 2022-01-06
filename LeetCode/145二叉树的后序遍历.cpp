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
void post_order(struct TreeNode *root, int *res, int *returnSize) {
    if (root == NULL) return ;
    post_order(root->left, res, returnSize);
    post_order(root->right, res, returnSize);
    res[(*returnSize)++] = root->val;
    return ;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 505);
    *returnSize = 0;
    post_order(root, res, returnSize);
    return res;
}