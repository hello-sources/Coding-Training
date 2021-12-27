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
#define MAX_N 10000

int* levelOrder(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int *res = (int *)malloc(sizeof(int) * MAX_N);
    struct TreeNode *queue[MAX_N];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head != tail) {
        int last = tail;
        while (head < last) {
            struct TreeNode *cur = queue[head++];
            res[(*returnSize)++] = cur->val;
            if (cur->left) queue[tail++] = cur->left;
            if (cur->right) queue[tail++] = cur->right;
        }
    }
    return res;
}