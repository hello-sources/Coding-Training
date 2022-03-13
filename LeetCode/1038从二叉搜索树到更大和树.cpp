/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int num[105];
int size;

void in_order(struct TreeNode *root, int *num, int *size) {
    if (root == NULL) return ;
    in_order(root->left, num, size);
    num[(*size)++] = root->val;
    in_order(root->right, num, size);
    return ; 
}

int calc(int x) {
    int sum = 0, sumx = 0;
    for (int i = 0; i < size; i++) {
        if (num[i] < x) sum += num[i];
        sumx += num[i];
    }
    return sumx - sum;
}

void change(struct TreeNode *root) {
    if (root == NULL) return ;
    change(root->left);
    root->val = calc(root->val);
    change(root->right);
    return ;
}

struct TreeNode* bstToGst(struct TreeNode* root){
    memset(num, 0, sizeof(num));
    size = 0;
    in_order(root, num, &size);
    change(root);
    return root;
}