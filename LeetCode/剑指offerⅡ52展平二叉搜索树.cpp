/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *getNewNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void in_order(struct TreeNode *node, int *res, int *resSize) {
    if (node == NULL) return;
    in_order(node->left, res, resSize);
    res[(*resSize)++] = node->val;
    in_order(node->right, res, resSize);
    return ;
}

struct TreeNode* increasingBST(struct TreeNode* root){
    int res[100], resSize = 0;
    in_order(root, res, &resSize);
    struct TreeNode *p = getNewNode(-1);
    struct TreeNode *q = p;
    for (int i = 0; i < resSize; i++) {
        q->right = getNewNode(res[i]);
        q = q->right;
    }
    return p->right;
}