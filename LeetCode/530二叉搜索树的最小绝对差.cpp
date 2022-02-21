/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void order(struct TreeNode *root, int *num, int *size) {
    if (root == NULL) return ;
    order(root->left, num, size);
    num[(*size)++] = root->val;
    order(root->right, num, size);
    return ;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int getMinimumDifference(struct TreeNode* root){
    int *res = (int *)malloc(sizeof(int) * 10005);
    int size = 0;
    order(root, res, &size);
    qsort(res, size, sizeof(int), cmp);
    int min = INT_MAX;
    for (int i = 1; i < size; i++) {
        min = fmin(min, res[i] - res[i - 1]);
    }
    free(res);
    return min;
}