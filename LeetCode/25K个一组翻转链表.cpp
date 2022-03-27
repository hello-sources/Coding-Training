/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *temp = head;
    int len = 0;
    while (temp) {
        temp = temp->next;
        len++;
    }
    int num[len], ind = 0;
    temp = head;
    while (temp) {
        num[ind++] = temp->val;
        temp = temp->next;
    }
    for (int i = 0; i + k <= len; i += k) {
        for (int l = i, r = i + k - 1; l < r; l++, r--) {
            int t = num[l];
            num[l] = num[r];
            num[r] = t;
        }
    }
    ind = 0;
    temp = head;
    while (temp) {
        temp->val = num[ind++];
        temp = temp->next;
    }
    return head;
}