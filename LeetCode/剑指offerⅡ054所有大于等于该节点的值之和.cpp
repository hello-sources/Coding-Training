/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum, temp;
void in_order(struct TreeNode *root) {
    if (root == NULL) return ;
    in_order(root->left);
    sum += root->val;
    in_order(root->right);
    return ;
}

void in_order1(struct TreeNode *root) {
    if (root == NULL) return ;
    in_order1(root->left);
    temp += root->val;
    root->val += (sum - temp);
    in_order1(root->right);
    return ;
}

struct TreeNode* convertBST(struct TreeNode* root){
    sum = temp = 0;
    in_order(root);
    in_order1(root);
    return root;
}