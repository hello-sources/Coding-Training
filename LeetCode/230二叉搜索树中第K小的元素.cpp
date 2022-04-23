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
    priority_queue<int, vector<int>, greater<int>> prq;
    void pre_order(TreeNode *root) {
        if (root == nullptr) return ;
        pre_order(root->left);
        prq.emplace(root->val);
        pre_order(root->right);
        return ;
    }

    int kthSmallest(TreeNode* root, int k) {
        pre_order(root);
        while (--k) prq.pop();
        return prq.top();
    }
};


/**********************stack*********************/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> sta;
        while(root != nullptr || sta.size() > 0) {
            while (root != nullptr) {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            --k;
            if (k == 0) break;
            root = root->right;
        }
        return root->val;
    }
};