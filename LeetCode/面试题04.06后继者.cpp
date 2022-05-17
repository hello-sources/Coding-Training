/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> sta;
        TreeNode *pre = nullptr, *cur = root;
        while (!sta.empty() || cur) {
            while (cur) {
                sta.emplace(cur);
                cur = cur->left;
            }
            cur = sta.top();
            sta.pop();
            if (pre == p) return cur;
            pre = cur;
            cur = cur->right;
        }
        return nullptr;
    }
};

/*******************二叉搜索树性质**********************/
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        if (p->right) {
            ans = p->right;
            while (ans->left) ans = ans->left;
            return ans;
        }
        TreeNode *node = root;
        while (node) {
            if (node->val > p->val) {
                ans = node;
                node = node->left;
            } else node = node->right;
        }
        return ans;
    }
};