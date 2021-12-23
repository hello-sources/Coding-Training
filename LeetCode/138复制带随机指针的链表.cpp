/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node *p = head;
    while (p != NULL) {
        struct Node *new_node = calloc(1, sizeof(struct Node));
        new_node->val = p->val;
        new_node->next = p->next;
        new_node->random = NULL;
        p->next = new_node;
        p = new_node->next;
    }
    p = head;
    while (p != NULL) {
        if (p->random != NULL) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }
    struct Node *res = calloc(1, sizeof(struct Node));
    struct Node *cur = res;
    p = head;
    while (p != NULL) {
        cur->next = p->next;
        cur = p->next;
        p->next = cur->next;
        p = cur->next;
    }
    return res->next;
}