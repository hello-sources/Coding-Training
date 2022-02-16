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
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double *ans = (double *)malloc(sizeof(double) * 1005);
    struct TreeNode **p = (struct TreeNode *)malloc(sizeof(struct TreeNode) * 10001);
    *returnSize = 0;
    int pleft = 0, pright = 0;
    p[pright++] = root;
    while (pleft < pright) {
        double sum = 0;
        int size = pright - pleft;
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = p[pleft++];
            sum += node->val;
            struct TreeNode *temp_l = node->left, *temp_r = node->right;
            if (temp_l != NULL) p[pright++] = temp_l;
            if (temp_r != NULL) p[pright++] = temp_r;
        }
        ans[(*returnSize)++] = sum / size;
    }
    return ans;
}

/*** DFS版本
int countsSize;
int sumsSize;

void dfs(struct TreeNode* root, int level, int* counts, double* sums) {
    if (root == NULL) {
        return;
    }
    if (level < sumsSize) {
        sums[level] += root->val;
        counts[level] += 1;
    } else {
        sums[sumsSize++] = (double)root->val;
        counts[countsSize++] = 1;
    }
    dfs(root->left, level + 1, counts, sums);
    dfs(root->right, level + 1, counts, sums);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    countsSize = sumsSize = 0;
    int* counts = malloc(sizeof(int) * 1001);
    double* sums = malloc(sizeof(double) * 1001);
    dfs(root, 0, counts, sums);
    double* averages = malloc(sizeof(double) * 1001);
    *returnSize = sumsSize;
    for (int i = 0; i < sumsSize; i++) {
        averages[i] = sums[i] / counts[i];
    }
    return averages;
}
**/