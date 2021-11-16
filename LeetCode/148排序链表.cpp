/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *p = head;
    int cnt = 0, index = 0, res = 0;
    while (p) {
        p = p->next;
        cnt++;
    }
    p = head;
    int *ans = (int *)malloc(sizeof(int) * cnt);
    while (p) {
        ans[index++] = p->val;
        p = p->next;
    }
    qsort(ans, cnt, 4, cmp);
    p = head;
    while (p) {
        p->val = ans[res++];
        p = p->next;
    }
    return head;
}