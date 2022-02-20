/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_N 201
void get_node(struct TreeNode *root, int *nums, int *size) {
    if (!root->left && !root->right) nums[(*size)++] = root->val;
    else {
        if (root->left) {
            get_node(root->left, nums, size);
        }
        if (root->right) {
            get_node(root->right, nums, size);
        }
    } 
    return ;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int *nums_1 = (int *)malloc(sizeof(int) * MAX_N);
    int *nums_2 = (int *)malloc(sizeof(int) * MAX_N);
    int size1 = 0, size2 = 0;
    if (root1) {
        get_node(root1, nums_1, &size1);
    }
    if (root2) {
        get_node(root2, nums_2, &size2);
    }
    if (size1 != size2) return false;
    for (int i = 0; i < size1; i++) {
        if (nums_1[i] != nums_2[i]) return false;
    }
    return true;
}