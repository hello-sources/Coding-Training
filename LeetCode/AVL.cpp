#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define H(root) (root)->h
#define L(root) (root)->lchild
#define R(root) (root)->rchild

typedef struct Node {
    int val, h;
    struct Node *lchild, *rchild;
} Node;

Node _NIL, *NIL = (&_NIL);
__attribute__((constructor))
void init_NIL() {
    NIL->val = 0;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->h = 1;
    node->val = val;
    node->lchild = node->rchild = NIL;
    return node;
}

void UpdateHeight(Node *root) {
    H(root) = fmax(H(L(root)), H(R(root))) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    UpdateHeight(root);
    UpdateHeight(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    UpdateHeight(root);
    UpdateHeight(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
        if (H(R(L(root))) > H(L(L(root)))) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (H(L(R(root))) > H(R(R(root)))) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->val == val) return root;
    if (root->val < val) root->rchild = insert(root->rchild, val);
    else root->lchild = insert(root->lchild, val);
    UpdateHeight(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NIL) return root;
    if (root->val > val) root->lchild = erase(root->lchild, val);
    else if (root->val < val) root->rchild = erase(root->rchild, val);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->val = temp->val;
            root->lchild =  erase(root->lchild, temp->val);
        }
    }
    UpdateHeight(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d [%d, %d]\n", root->val, L(root)->val, R(root)->val);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        output(root);
    }
    clear(root);
    return 0;
}