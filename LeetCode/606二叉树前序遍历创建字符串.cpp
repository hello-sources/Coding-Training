/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void in_order(struct TreeNode *node, char *s, int *len) {
    if (node == NULL) return ;
    *len += sprintf(s + *len, "%d", node->val);
    if (node->left || node->right) {
        *len += sprintf(s + *len, "%s", "(");
        in_order(node->left, s, len);
        *len += sprintf(s + *len, "%s", ")");
    }
    if (node->right) {
        *len += sprintf(s + *len, "%s", "(");
        in_order(node->right, s, len);
        *len += sprintf(s + *len, "%s", ")");
    }
    return ;
}

char * tree2str(struct TreeNode* root){
    char *s = (char *)malloc(sizeof(char) * 40000);
    int len = 0;
    in_order(root, s, &len);
    s[len] = '\0';
    return s;
}