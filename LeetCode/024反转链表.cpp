/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = NULL, *q;
    while (head) {
        q = head;
        head = head->next;
        q->next = p;
        p = q;
    }
    return p;
}