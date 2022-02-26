/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *calc(struct ListNode *x, int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (x == NULL) return x;
        x = x->next;
    }
    return x;
}

struct ListNode* deleteNodes(struct ListNode* head, int m, int n){
    struct ListNode *p = head, *q;
    while (p) {
        q = calc(p, m + n);
        p = calc(p, m - 1);
        if (p) {
            p->next = q;
            p = q;
        }
    }
    return head;
}