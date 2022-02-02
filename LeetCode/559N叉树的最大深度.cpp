/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
void get_depth(struct Node *root, int *ans, int depth) {
    if (root == NULL) return ;
    *ans = fmax(*ans, depth);
    for (int i = 0; i < root->numChildren; i++) {
        get_depth(root->children[i], ans, depth + 1);
    }
    return ;
}

int maxDepth(struct Node* root) {
    int max_depth = 0;
    get_depth(root, &max_depth, 1);
    return max_depth;
}