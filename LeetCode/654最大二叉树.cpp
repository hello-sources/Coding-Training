/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int calc(int *nums, int l, int r) {
    int max = l;
    for (int i = l; i < r; i++) {
        if (nums[max] < nums[i]) max = i;
    }
    return max;
}

struct TreeNode* construct(int *nums, int l, int r) {
    if (l == r) return NULL;
    int max = calc(nums, l, r);
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[max];
    node->left = construct(nums, l, max);
    node->right = construct(nums, max + 1, r);
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return construct(nums, 0, numsSize);
}