/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode *root, int x, int y, int depth) {
    if (root == NULL) return 0;
    if (root->val == x || root->val == y) return depth;
    int l = dfs(root->left, x, y, depth + 1);
    int r = dfs(root->right, x, y, depth + 1);
    if (l < 0) return l;
    if (r < 0) return r;
    if (l > 0 && r > 0) {
        if (l == r && l != depth + 1) return -1;
        else return -2;
    }
    if (l > 0) return l;
    if (r > 0) return r;
    return 0;
}

bool isCousins(struct TreeNode* root, int x, int y){
    return dfs(root, x, y, 1) == -1;
}