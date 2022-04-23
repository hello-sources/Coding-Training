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
private :
    priority_queue<int, vector<int>, greater<int>> prq;

public:
    void pre_order(TreeNode *root) {
        if (root == nullptr) return ;
        pre_order(root->left);
        prq.emplace(root->val);
        pre_order(root->right);
        return ;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        pre_order(root1);
        pre_order(root2);
        while (!prq.empty()) {
            ans.emplace_back(prq.top());
            prq.pop();
        }
        return ans;
    }
};

/***********************************************/
class Solution {
public:
    void pre_order(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) return ;
        pre_order(root->left, ans);
        ans.emplace_back(root->val);
        pre_order(root->right, ans);
        return ;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        pre_order(root1, ans);
        pre_order(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};