/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_N 10005
int *num, top;
void pre_order(struct TreeNode *node) {
    if (node == NULL) return ;
    pre_order(node->left);
    num[top++] = node->val;
    pre_order(node->right);
    return ;
}

bool findTarget(struct TreeNode* root, int k){
    num = (int *)malloc(sizeof(int) * MAX_N);
    top = 0;
    pre_order(root);
    int left = 0, right =  top - 1;
    while (left < right) {
        if (num[left] + num[right] < k) left++;
        else if (num[left] + num[right] > k) right--;
        else return true;
    }
    return false;
}