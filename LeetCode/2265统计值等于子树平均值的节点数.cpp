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
    void in_order(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) return ;
        vec.emplace_back(root->val);
        in_order(root->left, vec);
        in_order(root->right, vec);
        return ;
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> vec;
        int sum = 0;
        in_order(root, vec);
        for (auto v : vec) sum += v;
        sum /= vec.size();
        if (sum == root->val) ans++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;
    }

private :
    int ans = 0;
};

/**********************返回值为pair**********************/
class Solution {
public:
    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) return {0, 0};
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        int sum = l.first + r.first + root->val, size = l.second + r.second + 1;
        if (sum / size == root->val) ans++;
        return {sum, size};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }

private :
    int ans;
};