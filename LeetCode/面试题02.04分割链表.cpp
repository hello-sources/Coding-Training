/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *ans = new ListNode(0);
        ListNode *pre_ans = ans;
        ListNode *temp = new ListNode(0);
        ListNode *pre_temp = temp;
        while (head) {
            if (head->val < x) {
                ans->next = head;
                ans = ans->next;
            } else {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = nullptr;
        ans->next = pre_temp->next;
        return pre_ans->next;
    }
};