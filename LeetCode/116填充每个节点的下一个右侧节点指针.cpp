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

//C++做法
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* nodePre;
            Node* node;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                } else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            nodePre->next = NULL;
        }
        return root;
    }
};