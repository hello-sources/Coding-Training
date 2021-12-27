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
void swap(int *a, int *b) {
    int i = *a;
    *a = *b;
    *b = i;
    return ;
}

void reverse(int *num, int size) {
    for (int i = 0; i * 2 < size; i++) swap(&num[i], &num[size - i - 1]);
    // int left = 0, right = size - 1;
    // while (left < right) {
    //     int temp = num[left];
    //     num[left] = num[right];
    //     num[right] = temp;
    //     left++;
    //     right--;
    // }
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int **res = (int **)malloc(sizeof(int *) * MAX_N);
    memset(res, 0, sizeof(int *) * MAX_N);
    *returnColumnSizes = (int *)malloc(sizeof(int *) * MAX_N);
    memset(*returnColumnSizes, 0, sizeof(int *) * MAX_N);
    struct TreeNode *queue[MAX_N] = {0};
    int head = 0, tail = 0, level = 0;
    queue[tail++] = root;
    while (head < tail) {
        int size = (tail - head + MAX_N) % MAX_N;
        (*returnColumnSizes)[*returnSize] = size;
        res[*returnSize] = (int *)malloc(sizeof(int) * MAX_N);
        int *temp = (int *)malloc(sizeof(int) * MAX_N);
        for (int i = 0; i < size; i++) {
            struct TreeNode *cur = queue[head++];
            temp[i] = cur->val;
            if (cur->left != NULL) queue[tail++] = cur->left;
            if (cur->right != NULL) queue[tail++] = cur->right;
        }
        if (level % 2) reverse(temp, size);
        res[(*returnSize)++] = temp;
        level++;
    }
    return res;
}