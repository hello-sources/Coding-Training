/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *root, int val, int *sum) {
    if (root == NULL) return ;
    val = (val << 1) + root->val;
    if (!root->left && !root->right) *sum += val;
    dfs(root->left, val, sum);
    dfs(root->right, val, sum);
    return ;
}

int sumRootToLeaf(struct TreeNode* root){
    int sum = 0;
    dfs(root, 0, &sum);
    return sum;
}   