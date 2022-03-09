/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans;
void dfs(int gVal, int pVal, struct TreeNode *root) {
    if (root == NULL) return ;
    if (gVal % 2 == 0) ans += root->val;
    dfs(pVal, root->val, root->left);
    dfs(pVal, root->val, root->right);
    return ;
}

int sumEvenGrandparent(struct TreeNode* root){
    ans = 0;
    dfs(1, 1, root);
    return ans;
}