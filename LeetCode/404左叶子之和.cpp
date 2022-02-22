/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool judge(struct TreeNode *node) {
    return (!node->left && !node->right);
}

int calc(struct TreeNode *root) {
    int ans = 0;
    if (root->left) {
        ans += judge(root->left) ? root->left->val : calc(root->left);
    }
    if (root->right && !judge(root->right)) {
        ans += calc(root->right);
    }
    return ans;
}

int sumOfLeftLeaves(struct TreeNode* root){
    int ans = 0;
    ans = calc(root);
    return ans;
}