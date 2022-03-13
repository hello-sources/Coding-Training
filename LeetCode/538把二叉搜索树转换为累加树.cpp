int sum;

struct TreeNode* dfs(struct TreeNode* root) {
    if (root != NULL) {
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
    return root;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    sum = 0;
    dfs(root);
    return root;
}