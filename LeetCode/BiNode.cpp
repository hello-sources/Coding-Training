/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *head = NULL, *curr = NULL;

void dfs(struct TreeNode *node) {
    if (node == NULL) return NULL;
    dfs(node->left);
    if (head == NULL) {
        head = curr = node;
    } else {
        curr->right = node;
        curr = curr->right;
    }
    node->left = NULL;
    dfs(node->right);
}

struct TreeNode* convertBiNode(struct TreeNode* root){
    if (root == NULL) return NULL;
    head = NULL;
    curr = NULL;
    dfs(root);
    return head;
}
