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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        stack<TreeNode *> sta;
        TreeNode *cur = root, *pre = nullptr;
        while (cur != nullptr || !sta.empty()) {
            while (cur != nullptr) {
                if (pre != nullptr) {
                    cur->val += pre->val * 10;
                }
                sta.push(cur);
                pre = cur;
                cur = cur->left;
            }
            cur = sta.top();
            sta.pop();
            if (cur->left == nullptr && cur->right == nullptr) sum += cur->val;
            pre = cur;
            cur = cur->right;
        }
        return sum;
    }
};