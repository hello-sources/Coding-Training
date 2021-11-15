/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rev(struct ListNode *head, int *len) {
    struct ListNode *p = NULL, *q;
    while (head) {
        q = head;
        head = head->next;
        q->next = p;
        p = q;
        (*len)++;
    }
    return p;
}

int getDecimalValue(struct ListNode* head){
    int len = 0, ans = 0;
    struct ListNode *p = rev(head, &len);
    for (int i = 0; i < len; i++) {
        ans += p->val * pow(2, i);
        p = p->next;
    }
    return ans;
}