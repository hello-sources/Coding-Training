/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* upsideDownBinaryTree(struct TreeNode* root){
    struct TreeNode *parent = NULL;
    struct TreeNode *parent_left = NULL;
    struct TreeNode *parent_right = NULL;
    while(root != NULL){
        parent_left = root->left;
        root->left = parent_right;
        parent_right = root->right;
        root->right = parent;
        parent = root;
        root = parent_left;
    }
    return parent;
}