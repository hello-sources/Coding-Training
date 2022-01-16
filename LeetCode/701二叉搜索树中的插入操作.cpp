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

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (root == NULL) return getNewNode(val);
    struct TreeNode *node = root;
    while (node != NULL) {
        if (node->val > val) {
            if (node->left == NULL) {
                node->left = getNewNode(val);
                break;
            } else {
                node = node->left;
            }
        } else {
            if (node->right == NULL) {
                node->right = getNewNode(val);
                break;
            } else {
                node = node->right;
            }
        }
    }
    return root;
}