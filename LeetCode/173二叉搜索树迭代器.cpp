/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode *cur;
    struct TreeNode *stack[150];
    int size;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    obj->cur = root;
    obj->size = 0;
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    while (obj->cur != NULL) {
        obj->stack[(obj->size)++] = obj->cur;
        obj->cur = obj->cur->left;
    }
    obj->cur = obj->stack[--(obj->size)];
    int val = obj->cur->val;
    obj->cur = obj->cur->right;
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->cur != NULL || obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
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
/************************法2**********************/

typedef struct {
    int *num;
    int size, ind;
} BSTIterator;

int calcSize(struct TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + calcSize(root->left) + calcSize(root->right);
}

void inorder(struct TreeNode *root, int *size, int *res) {
    if (root == NULL) return ;
    inorder(root->left, size, res);
    res[(*size)++] = root->val;
    inorder(root->right, size, res);
}

int *in_order(int *size, struct TreeNode *root) {
    *size = 0;
    int temp = calcSize(root);
    int *res = (int *)malloc(sizeof(int) * temp);
    inorder(root, size, res);
    return res;
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    obj->num = in_order(&(obj->size), root);
    obj->ind = 0;
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->num[(obj->ind)++];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->ind < obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->num);
    free(obj);
    return ;
}