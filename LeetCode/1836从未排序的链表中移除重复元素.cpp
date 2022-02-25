/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicatesUnsorted(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = -1;
    p->next = head;
    int num[100005] = {0};
    int len = 0;
    while (head) {
        num[head->val]++;
        head = head->next;
    }
    struct ListNode *q = p;
    while (q && q->next) {
        if (num[q->next->val] > 1) q->next = q->next->next;
        else q = q->next;
    }
    return p->next;
}