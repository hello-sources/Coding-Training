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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> tree;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> ltree = generateTrees(start, i - 1);
            vector<TreeNode*> rtree = generateTrees(i + 1, end);
            for (auto &lch : ltree) {
                for (auto &rch : rtree) {
                    TreeNode *temp = new TreeNode(i);
                    temp->left = lch;
                    temp->right = rch;
                    tree.emplace_back(temp);
                }
            }
        }
        return tree;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};