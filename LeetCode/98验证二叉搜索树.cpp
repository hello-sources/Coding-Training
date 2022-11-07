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



/**
 * C++
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &vec) {
        if (root == nullptr) return ;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
        return ;
    }

    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};