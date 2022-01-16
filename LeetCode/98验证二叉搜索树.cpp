/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// bool judge(struct TreeNode *node, long a, long b) {
//     if (node == NULL) return true;
//     if (node->val <= a || node->val >= b) return false;
//     return judge(node->left, a, node->val) && judge(node->right, node->val, b);
// }

// bool isValidBST(struct TreeNode* root){
//     if (root == NULL) return true;
//     return judge(root, LONG_MIN, LONG_MAX);
// }
#define MAX_N 10005
int *num, cnt;

void pre_order(struct TreeNode *node) {
    if (node == NULL) return ;
    pre_order(node->left);
    num[cnt++] = node->val;
    pre_order(node->right);
    return ;
}

bool isValidBST(struct TreeNode* root){
    num = (int *)malloc(sizeof(int) * MAX_N);
    cnt = 0;
    pre_order(root);
    for (int i = 1; i < cnt; i++) {
        if (num[i - 1] >= num[i]) return false;
    }
    return true;
}