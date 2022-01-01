#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->val == val) return root;
    if (root->val > val) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NULL) return root;
    if (root->val < val) root->lchild = erase(root->lchild, val);
    else if (root->val < val) root->rchild = erase(root->rchild, val);
    else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->val = temp->val;
            root->lchild = erase(root->lchild, temp->val);
        }
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    free(root->lchild);
    free(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d ", root->val);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 6, val = rand() % 10;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d to binary tree!\n", val);
                root = insert(root, val);
                break;
            }
            case 3: 
            case 4:
            case 5: {
                printf("erase %d from binary tree!\n", val);
                root = erase(root, val);
                break;
            }
        }
        output(root), printf("\n");
    }
    free(root);
    return 0;
}