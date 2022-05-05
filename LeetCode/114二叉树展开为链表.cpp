/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> vec;
        stack<TreeNode*> sta;
        TreeNode *node = root;
        while (node != nullptr || !sta.empty()) {
            while (node != nullptr) {
                vec.push_back(node);
                sta.push(node);
                node = node->left;
            }
            node = sta.top();
            sta.pop();
            node = node->right;
        }
        int size = vec.size();
        for (int i = 1; i < size; i++) {
            TreeNode *pre = vec.at(i - 1), *cur = vec.at(i);
            pre->left = nullptr;
            pre->right = cur;
        }
        return ;
    }
};

/******************************寻找前驱节点************************/
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode *next = cur->left;
                TreeNode *precedessor = next;
                while (precedessor->right != nullptr) precedessor = precedessor->right;
                precedessor->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
        return ;
    }
};