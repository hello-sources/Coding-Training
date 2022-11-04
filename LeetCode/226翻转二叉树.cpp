/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    struct TreeNode *l = mirrorTree(root->left);
    struct TreeNode *r = mirrorTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

/**
 * C++做法
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> sta;
        if (root == nullptr) return root;
        sta.push(root);
        while (!sta.empty()) {
            TreeNode* node = sta.top();
            sta.pop();
            swap(node->left, node->right);
            if (node->right) sta.push(node->right);
            if (node->left) sta.push(node->left);
        }
        return root;
    }
};