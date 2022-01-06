/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = &ret;
    while (p && p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}

// struct ListNode* removeElements(struct ListNode* head, int val){
//     struct ListNode *p = head;
//     if (p == NULL) return head;
//     p->next = removeElements(p->next, val);
//     return (p->val == val)? p->next : p;
// }