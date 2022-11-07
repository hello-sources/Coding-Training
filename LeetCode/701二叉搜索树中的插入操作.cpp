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


/**
 * C++迭代
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* pre = root;
        TreeNode* cur = root;
        while (cur != nullptr) {
            pre = cur;
            if (cur->val > val) cur = cur->left;
            else if (cur->val <= val) cur = cur->right;
        }
        TreeNode* node = new TreeNode(val);
        if (val < pre->val) pre->left = node;
        else pre->right = node;
        return root;
    }
};