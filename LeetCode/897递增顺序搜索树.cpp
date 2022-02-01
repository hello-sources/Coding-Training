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
    node->left = node->right = NULL;
    node->val = val;
    return node;
}

void in_order(struct TreeNode *root, int *res, int *resSize) {
    if (root == NULL) return ;
    in_order(root->left, res, resSize);
    res[(*resSize)++] = root->val;
    in_order(root->right, res, resSize);
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