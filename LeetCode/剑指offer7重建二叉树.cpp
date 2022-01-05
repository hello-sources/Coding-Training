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
    int lsize, rsize, cnt = 0;
    while (inorder[cnt] != preorder[0]) cnt++;
    lsize = cnt;
    rsize = preorderSize - cnt - 1;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = preorder[0];
    node->left = buildTree(preorder + 1, lsize, inorder, lsize);
    node->right = buildTree(preorder + 1 + lsize, rsize, inorder + lsize + 1, rsize);
    return node;
}