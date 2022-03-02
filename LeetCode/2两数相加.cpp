/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, *tail = NULL;
    int sum = 0, car = 0;
    while (l1 || l2 || car) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        sum = x + y + car;
        car = sum / 10;
        if (head == NULL) {
            head = tail = (struct ListNode *)malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        } else {
            tail->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = sum % 10;
            tail->next = NULL;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return head;
}