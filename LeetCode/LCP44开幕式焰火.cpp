/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *cnt;

void in_order(struct TreeNode* root) {
    if (root == NULL) return ;
    in_order(root->left);
    cnt[root->val]++;
    in_order(root->right);
    return ;
}

int numColor(struct TreeNode* root){
    int ans = 0;
    cnt = (int *)malloc(sizeof(int) * 1005);
    memset(cnt, 0, sizeof(int) * 1005);
    in_order(root);
    for (int i = 0; i < 1005; i++) {
        if (cnt[i]) ans += 1;
    }
    return ans;
}