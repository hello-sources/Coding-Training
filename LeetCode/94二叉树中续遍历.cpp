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

void inorder(struct TreeNode *root, int* res, int *returnSize) {
    if (root == NULL) return ;
    inorder(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inorder(root->right, res, returnSize);
    return ;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 505);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}