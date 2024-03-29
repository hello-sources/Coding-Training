/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p = list1;
        ListNode *temp = list2;
        ListNode *q = p->next;
        while (--a) p = p->next;
        while (b--) q = q->next;
        p->next = list2;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = q;
        return list1;
    }
};