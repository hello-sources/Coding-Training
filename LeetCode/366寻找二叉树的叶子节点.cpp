// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */


// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
#define MAX_N 100
int get_num(struct TreeNode *root, int *returnSize, int **returnColumnSizes, int **res) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        res[*returnSize][(*returnColumnSizes)[*returnSize]++] = root->val;
        return 1;
    }
    int left = get_num(root->left, returnSize, returnColumnSizes, res);
    if (left) root->left = NULL;
    int right = get_num(root->right, returnSize, returnColumnSizes, res);
    if (right) root->right = NULL;
    return 0;
}

int** findLeaves(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        res[i] = (int *)calloc(MAX_N, sizeof(int));
    }
    *returnColumnSizes = (int *)calloc(MAX_N, sizeof(int));
    *returnSize = 0;
    while (root) {
        int temp = get_num(root, returnSize, returnColumnSizes, res);
        if (temp) root = NULL;
        (*returnSize)++;
    }
    return res;
}