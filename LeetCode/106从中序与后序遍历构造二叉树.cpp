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
    TreeNode *build(vector<int>& inorder, int leftInorder, int rightInorder, vector<int> &postorder, int leftPostOrder, int rightPostOrder) {
        if (leftPostOrder == rightPostOrder) return nullptr;
        int rootVal = postorder[rightPostOrder - 1];
        TreeNode *root = new TreeNode(rootVal);
        if (rightPostOrder - leftPostOrder == 1) return root;
        int ind;
        for (ind = leftInorder; ind < rightInorder; ind++) {
            if (inorder[ind] == root->val) break;
        }         
        int leftInorderLeft = leftInorder;
        int leftInorderRight = ind;     
        int rightInorderLeft = ind + 1;
        int rightInorderRight = rightInorder;

        int leftPostOrderLeft = leftPostOrder;
        int leftPostOrderRight = leftPostOrder + ind - leftInorder;
        int rightPostOrderLeft = leftPostOrder + ind - leftInorder;
        int rightPostOrderRight = rightPostOrder - 1;
        root->left = build(inorder, leftInorderLeft, leftInorderRight, postorder, leftPostOrderLeft, leftPostOrderRight);
        root->right = build(inorder, rightInorderLeft, rightInorderRight, postorder, rightPostOrderLeft, rightPostOrderRight);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};