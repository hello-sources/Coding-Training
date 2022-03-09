/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *root, int cur, int *depth, int *sum) {
    if (root == NULL) return ;
    if (cur > *depth) {
        *depth = cur;
        *sum = 0;
    }
    if (*depth == cur) *sum += root->val;
    dfs(root->left, cur + 1, depth, sum);
    dfs(root->right, cur + 1, depth, sum);
    return ;
}

int deepestLeavesSum(struct TreeNode* root){
    int depth = 0, sum = 0;
    dfs(root, 0, &depth, &sum);
    return sum;
}