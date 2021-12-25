/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_N 100001

bool isEvenOddTree(struct TreeNode* root){
    struct TreeNode *qu[MAX_N];
    int head = 0, tail = 0;
    qu[head++] = root;
    int level = 0;
    while(tail < head) {
        int size = head - tail;
        int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = qu[tail++];
            int val = node->val;
            if (val % 2 == level % 2) return false;
            if ((level % 2 == 0 && val <= prev) || (level % 2 == 1 && val >= prev)) return false;
            prev = val;
            if (node->left != NULL) qu[head++] = node->left;
            if (node->right != NULL) qu[head++] = node->right;
        }
        level++;
    }
    return true;
}