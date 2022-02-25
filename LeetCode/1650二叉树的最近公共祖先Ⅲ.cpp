/*
// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};
*/

struct Node* lowestCommonAncestor(struct Node* p,struct Node* q) {
    struct Node *pa = p;
    struct Node *pb = q;
    while (pa != pb) {
        pa = pa->parent ? pa->parent : q;
        pb = pb->parent ? pb->parent : p;
    }
    return pa;
}