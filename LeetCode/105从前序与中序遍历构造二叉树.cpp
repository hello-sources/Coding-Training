/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize == 0 || inorderSize == 0) return NULL;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = preorder[0];
    int index;
    for (index = 0; index < inorderSize; index++) {
        if (inorder[index] == preorder[0]) break;
    }
    node->left = buildTree(preorder + 1, index, inorder, index);
    node->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, preorderSize - index - 1);
    return node;
}

/**C++版本**/
class Solution {
public:
    // TreeNode* build(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
    //     if (inorderEnd <= inorderBegin || preorderEnd <= preorderBegin) return NULL;
    //     int nodeVal = preorder[preorderBegin];
    //     TreeNode* node = new TreeNode(nodeVal);
    //     int index;
    //     for (index = inorderBegin; index < inorderEnd; index++) {
    //         if (inorder[index] == preorder[0]) break;
    //     }
    //     node->left = build(inorder, inorderBegin, index, preorder, preorderBegin + 1, preorderBegin + 1 + index - inorderBegin);
    //     node->right = build(inorder, index + 1, inorderEnd, preorder, preorderBegin + 1 + index - inorderBegin, preorderEnd);
    //     return node;
    // }

    TreeNode* build (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
        if (preorderBegin == preorderEnd) return NULL;
        int rootValue = preorder[preorderBegin]; 
        TreeNode* root = new TreeNode(rootValue);
        if (preorderEnd - preorderBegin == 1) return root;
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;
        int leftPreorderBegin =  preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin; 
        int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
        int rightPreorderEnd = preorderEnd;
        root->left = build(inorder, leftInorderBegin, leftInorderEnd,  preorder, leftPreorderBegin, leftPreorderEnd);
        root->right = build(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return build(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};