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
#define MAX_N 10005

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int **res = (int **)malloc(sizeof(int *) * MAX_N);
    memset(res, 0, sizeof(int *) * MAX_N);
    *returnColumnSizes = (int *)malloc(sizeof(int *) * MAX_N);
    memset(*returnColumnSizes, 0, sizeof(int *) * MAX_N);
    struct TreeNode *queue[MAX_N] = {0};
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        int size = (tail - head + MAX_N) % MAX_N;
        (*returnColumnSizes)[*returnSize] = size;
        res[*returnSize] = (int *)malloc(sizeof(int) * MAX_N);
        for (int i = 0; i < size; i++) {
            struct TreeNode *temp = queue[head++];
            res[*returnSize][i] = temp->val;
            if (temp->left != NULL) queue[tail++] = temp->left;
            if (temp->right != NULL) queue[tail++] = temp->right;
        }
        (*returnSize)++;
    }
    return res;
}