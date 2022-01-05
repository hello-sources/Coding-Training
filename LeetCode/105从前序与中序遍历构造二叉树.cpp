/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize == 0 || inorderSize == 0) return NULL;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = preorder[0];
    int index;
    for (index = 0; index < inorderSize; index++) {
        if (inorder[index] == preorder[0]) break;
    }
    node->left = buildTree(preorder + 1, index, inorder, index);
    node->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, preorderSize - index - 1);
    return node;
}