/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *nums;
int cnt = 0;

void pre_order(struct TreeNode *root) {
    if (root == NULL) return ;
    pre_order(root->left);
    nums[cnt++] = root->val;
    pre_order(root->right);
    return ;
}

int kthLargest(struct TreeNode* root, int k){
    nums = (int *)malloc(sizeof(int) * 100005);
    pre_order(root);
    int ans = nums[cnt - k];
    free(nums);
    return ans;
}