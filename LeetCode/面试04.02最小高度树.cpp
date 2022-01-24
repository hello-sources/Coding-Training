/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *build(int *nums, int left, int right) {
    if (left > right) return NULL;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int mid = (left + right) / 2;
    node->val = nums[mid];
    node->left = build(nums, left, mid - 1);
    node->right = build(nums, mid + 1, right);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) return NULL;
    int l = 0, r = numsSize - 1;
    return build(nums, l, r);
}