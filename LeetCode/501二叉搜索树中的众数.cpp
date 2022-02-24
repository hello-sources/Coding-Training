/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *ans;
int ansSize, base, cnt, max_cnt;

void update(int x) {
    if (x == base) cnt++;
    else {
        base = x;
        cnt = 1;
    }
    if (cnt == max_cnt) {
        ans[ansSize++] = base;
    }
    if (max_cnt < cnt) {
        max_cnt = cnt;
        ansSize = 0;
        ans[ansSize++] = base;
    }
}

void order(struct TreeNode *root) {
    if (root == NULL) return ;
    order(root->left);
    update(root->val);
    order(root->right);
    return ;
}

int* findMode(struct TreeNode* root, int* returnSize){
    base = cnt = max_cnt = ansSize = 0;
    ans = (int *)malloc(sizeof(int) * 4001);
    order(root);
    *returnSize = ansSize;
    return ans;
}