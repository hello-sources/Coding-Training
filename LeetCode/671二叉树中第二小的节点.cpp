/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void order(struct TreeNode *root, int *num, int *size) {
    if (root == NULL) return ;
    num[(*size)++] = root->val;
    order(root->left, num, size);
    order(root->right, num, size);
    return ;
}

int findSecondMinimumValue(struct TreeNode* root){
    int *num = (int *)malloc(sizeof(int) * 30);
    int size = 0;
    order(root, num, &size);
    qsort(num, size, sizeof(int), cmp);
    for (int i = 0; i < size; i++) {
        if (num[i] != num[0]) return num[i];
    }
    return -1;
}