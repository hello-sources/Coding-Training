/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int *num;
    int size, ind;
} BSTIterator;

int get_size(struct TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + get_size(root->left) + get_size(root->right);
}

void in_order(int *res, int *size, struct TreeNode *root) {
    if (root == NULL) return ;
    in_order(res, size, root->left);
    res[(*size)++] = root->val;
    in_order(res, size, root->right);
    return ;
}

int *order(int *size, struct TreeNode *root) {
    *size = 0;
    int temp_size = get_size(root);
    int *res = (int *)malloc(sizeof(int) * temp_size);
    in_order(res, size, root);
    return res;
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    obj->num = order(&obj->size, root);
    obj->ind = 0;
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->num[obj->ind++];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->ind < obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->num);
    free(obj);
    return ;
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/