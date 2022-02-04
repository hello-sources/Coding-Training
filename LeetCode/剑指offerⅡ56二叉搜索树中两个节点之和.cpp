/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void in_order(struct TreeNode *root, int *num, int *size) {
    if (root == NULL) return ;
    in_order(root->left, num, size);
    num[(*size)++] = root->val;
    in_order(root->right, num, size);
    return ;
}

bool findTarget(struct TreeNode* root, int k){
    if (root == NULL) return false;
    int *num = (int *)malloc(sizeof(int) * 10005);
    int size = 0;
    in_order(root, num, &size);
    int left = 0, right = size - 1;
    while (left < right) {
        int sum = num[left] + num[right];
        if (sum == k) return true;
        else if (sum < k) left++;
        else right--;
    }
    return false;
}