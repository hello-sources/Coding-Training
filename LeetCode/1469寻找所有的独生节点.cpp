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
#define MAX_N 1001
void order(struct TreeNode *root, int *num, int *numSize) {
    if (root == NULL) return ;
    order(root->left, num, numSize);
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
        num[(*numSize)++] = root->left ? root->left->val : root->right->val;
    } 
    order(root->right, num, numSize);
    return ;
}

int* getLonelyNodes(struct TreeNode* root, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * MAX_N);
    int resSize = 0;
    order(root, res, &resSize);
    *returnSize = resSize;
    return res;
}