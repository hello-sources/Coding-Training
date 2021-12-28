/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *temp;
bool dfs(struct TreeNode *A, struct TreeNode *B) {
    if (B == NULL) return true;
    if (A == NULL) return false;
    if (A->val == B->val) {
        if (dfs(A->left, B->left) && dfs(A->right, B->right)) return true;
    }
    return dfs(A->left, temp) || dfs(A->right, temp);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if (B == NULL) return false;
    temp = B;
    return dfs(A, B);
}