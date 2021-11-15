/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// int kthToLast(struct ListNode* head, int k){
//     struct ListNode *p = head, *q = head;
//     int cnt = 0;
//     while (p) {
//         p = p->next;
//         cnt++;
//     }
//     for (int i = 0; i < cnt - k; i++) {
//         q = q->next;
//     }
//     return q->val;
// }

int kthToLast(struct ListNode* head, int k){
    struct ListNode *p = head, *q = head;
    for (int i = 0; i < k - 1; i++) {
        p = p->next;
    }
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    return q->val;
}