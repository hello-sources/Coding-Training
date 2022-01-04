/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **res;
int *resColsize, *path;
int ressize, pathsize;

void dfs(struct TreeNode *root, int target) {
    if (root == NULL) return ;
    path[pathsize++] = root->val;
    target -= root->val;
    if (root->left == NULL && root->right == NULL && target == 0) {
        int *temp = (int *)malloc(sizeof(int) * pathsize);
        memcpy(temp, path, sizeof(int) * pathsize);
        res[ressize] = temp;
        resColsize[ressize++] = pathsize;
    }
    dfs(root->left, target);
    dfs(root->right, target);
    pathsize--;
    return ;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    res = (int **)malloc(sizeof(int *) * 2005);
    resColsize = (int *)malloc(sizeof(int) * 2005);
    path = (int *)malloc(sizeof(int) * 2005);
    ressize = pathsize = 0;
    dfs(root, targetSum);
    *returnSize = ressize;
    *returnColumnSizes = resColsize;
    return res;
}