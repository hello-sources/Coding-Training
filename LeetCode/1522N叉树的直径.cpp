/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
int cnt = 0;
int dfs(struct Node *root) {
    int max = 0, temp = 0;
    for (int i = 0; i < root->numChildren; i++) {
        int j = dfs(root->children[i]) + 1;
        if (j > max) {
            temp = max;
            max = j;
        } else if (j > temp) {
            temp = j;
        }
    }
    cnt = fmax(cnt, max + temp);
    return max;
}

int* diameter(struct Node* root) {
    cnt = 0;
    dfs(root);
    return cnt;
}