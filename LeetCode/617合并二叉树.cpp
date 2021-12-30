/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;
    struct TreeNode *tree = malloc(sizeof(struct TreeNode));
    tree->val = root1->val + root2->val;
    tree->left = mergeTrees(root1->left, root2->left);
    tree->right = mergeTrees(root1->right, root2->right);
    return tree;
}