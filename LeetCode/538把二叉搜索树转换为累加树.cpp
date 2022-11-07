int sum;

struct TreeNode* dfs(struct TreeNode* root) {
    if (root != NULL) {
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
    return root;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    sum = 0;
    dfs(root);
    return root;
}


/**
 * C++版本
 */
class Solution {
public:
    void calc(TreeNode* root, int sum) {
        stack<TreeNode*> sta;
        TreeNode* cur = root;
        // if (root != nullptr) sta.push(root);
        while (cur != nullptr || !sta.empty()) {
            if (cur != nullptr) {
                sta.push(cur);
                cur = cur->right;
            } else {
                cur = sta.top();
                sta.pop();
                cur->val += sum;
                sum = cur->val;
                cur = cur->left;
            }
        }
        return ;
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        calc(root, sum);
        return root;
    }
};