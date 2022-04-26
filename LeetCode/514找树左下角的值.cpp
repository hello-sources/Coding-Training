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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            ans = temp->val;
            int size = que.size();
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
            for (int i = 0; i < size; i++) {
                temp = que.front();
                que.pop();
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
        }
        return ans;
    }
};