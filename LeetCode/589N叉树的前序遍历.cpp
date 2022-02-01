/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void pre_order(struct Node *root, int *res, int *returnSize) {
    if (root == NULL) return ;
    res[(*returnSize)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        pre_order(root->children[i], res, returnSize);
    }
    return ;
}

int* preorder(struct Node* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 10005);
    *returnSize = 0;
    pre_order(root, res, returnSize);
    return res;
}