/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int pairSum(struct ListNode* head){
    int *num = (int *)malloc(sizeof(int) * 100005);
    struct ListNode *p = head;
    int cnt = 0, ans = 0;
    while (p) {
        num[cnt++] = p->val;
        p = p->next;
    }
    for (int i = 0; i < cnt / 2; i++) {
        ans = fmax(ans, num[i] + num[cnt - i - 1]);
    }
    return ans;
}