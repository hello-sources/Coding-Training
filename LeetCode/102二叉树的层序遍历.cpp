/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_N 10005

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int **res = (int **)malloc(sizeof(int *) * MAX_N);
    memset(res, 0, sizeof(int *) * MAX_N);
    *returnColumnSizes = (int *)malloc(sizeof(int *) * MAX_N);
    memset(*returnColumnSizes, 0, sizeof(int *) * MAX_N);
    struct TreeNode *queue[MAX_N] = {0};
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        int size = (tail - head + MAX_N) % MAX_N;
        (*returnColumnSizes)[*returnSize] = size;
        res[*returnSize] = (int *)malloc(sizeof(int) * MAX_N);
        for (int i = 0; i < size; i++) {
            struct TreeNode *temp = queue[head++];
            res[*returnSize][i] = temp->val;
            if (temp->left != NULL) queue[tail++] = temp->left;
            if (temp->right != NULL) queue[tail++] = temp->right;
        }
        (*returnSize)++;
    }
    return res;
}


//C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};