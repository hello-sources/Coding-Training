/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL) return NULL;
	int left = 0, right = 0;
    struct Node *queue[5000];
    queue[right++] = root;
    while (left < right) {
        int size = right - left;
        for (int i = 0; i < size; i++) {
            struct Node *node = queue[left++];
            if (i < size - 1) node->next = queue[left];
            if (node->left != NULL) queue[right++] = node->left;
            if (node->right != NULL) queue[right++] = node->right;
        }
    }
    return root;
}