/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
void preorder(struct TreeNode *root, char *res) {
    if (root == NULL) {
        strcat(res, "#,");
        return ;
    }
    char temp[10] = "";
    sprintf(temp, "%d", root->val);
    strcat(res, temp);
    strcat(res, ",");
    preorder(root->left, res);
    preorder(root->right, res);
    return ;
}

char* serialize(struct TreeNode* root) {
    char *res = (char *)malloc(sizeof(char) * 50000);
    memset(res, 0, sizeof(res));
    preorder(root, res);
    return res;
}

struct TreeNode *build(char *data, int *ind) {
    if (data[*ind] == '#') {
        (*ind) += 2;
        return NULL;
    }
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    char temp[10] = "";
    for (int i = 0; data[*ind] != ','; i++, ++(*ind)) {
        temp[i] = data[*ind];
    }
    ++(*ind);
    node->val = atoi(temp);
    node->left = build(data, ind);
    node->right = build(data, ind);
    return node;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int ind = 0;
    return build(data, &ind);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);