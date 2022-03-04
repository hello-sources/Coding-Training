/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode *cur = head->next;
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    res->next = NULL;
    struct ListNode *pre = res;
    int sum = 0;
    while (cur) {
        if (cur->val > 0) sum += cur->val;
        else {
            struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newnode->val = sum;
            newnode->next = NULL;
            pre->next = newnode;
            pre = newnode;
            pre->next = NULL;
            sum = 0;
        }
        cur = cur->next;
    }
    return res->next;
}