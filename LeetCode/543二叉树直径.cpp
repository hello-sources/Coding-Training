/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans;
int get_depth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = get_depth(root->left);
    int r = get_depth(root->right);
    ans = fmax(ans, l + r);
    return fmax(l, r) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    ans = 0;
    get_depth(root);
    return ans;
}