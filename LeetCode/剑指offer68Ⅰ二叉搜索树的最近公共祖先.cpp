/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
//     if (root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p, q);
//     if (root->val < q->val && root->val < p->val) return lowestCommonAncestor(root->right, p, q);
//     return root;
// }

struct TreeNode *__lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root->val == p->val) return p;
    if (root->val == q->val) return q;
    if (root->val > p->val && q->val > root->val) return root;
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);
    return __lowestCommonAncestor(root->left, p, q);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val == q->val) return p;
    if (p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }//当前p是较小编号
    return __lowestCommonAncestor(root, p, q);
}