/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// struct ListNode* middleNode(struct ListNode* head){
//     int len = 0;
//     struct ListNode *phead = head;
//     while (phead) {
//         len++;
//         phead = phead->next;
//     } 
//     for (int i = 1; i <= len / 2; i++) {
//         head = head->next;
//     }
//     return head;
// }
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *p = head;
    struct ListNode *q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    return p;
}