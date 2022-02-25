/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* findNearestRightNode(struct TreeNode* root, struct TreeNode* u){
    int head = 0, tail = 0;
    struct TreeNode *queue[100000];
    struct TreeNode *cur;
    queue[tail++] = root;
    while (head < tail) {
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            cur = queue[head++];
            if (cur == u && i < size - 1) return queue[head];
            if (cur->left != NULL) queue[tail++] = cur->left;
            if (cur->right != NULL) queue[tail++] = cur->right;
        }
    }
    return NULL;
}