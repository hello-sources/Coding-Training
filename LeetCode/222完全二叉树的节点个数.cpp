/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void calc(struct TreeNode *root, int *cnt) {
    if (root == NULL) return ;
    calc(root->left, cnt);
    *cnt += 1;
    calc(root->right, cnt);
    return ;
}

int countNodes(struct TreeNode* root){
    int cnt = 0;
    calc(root, &cnt);
    return cnt;
}