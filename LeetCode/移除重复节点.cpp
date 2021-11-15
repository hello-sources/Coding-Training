/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode *p = head, *q = head->next;
    int temp[20005] = {0, 0, 0};
    int flag = 1;
    temp[p->val] = flag;
    while (q) {
        if (temp[q->val]) {
            p->next = q->next;
            q = q->next;
            continue;
        }
        temp[q->val] = flag;
        q = q->next;
        p = p->next;
    }
    return head;
}