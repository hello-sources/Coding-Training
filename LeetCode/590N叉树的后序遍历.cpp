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
void calc(struct Node *root, int *res, int *returnSize) {
    if (root == NULL) return ;
    for (int i = 0; i < root->numChildren; i++) {
        calc(root->children[i], res, returnSize);
    }
    res[(*returnSize)++] = root->val;
    return ;
}

int* postorder(struct Node* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 10001);
    *returnSize = 0;
    calc(root, res, returnSize);
    return res;
}