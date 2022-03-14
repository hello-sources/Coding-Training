/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    int num[100005], cnt = 0;
    memset(num, 0, sizeof(num));
    while (head != NULL) {
        num[cnt++] = head->val;
        head = head->next;
    }
    int l = 0, r = cnt - 1, count = 0;
    while (l <= r) {
        if (num[l] != num[r]) {
            if (num[l] == num[r - 1]) {
                r--;
                count++;
            } else if (num[l + 1] == num[r]) {
                l++;
                count++;
            } else return false;
            if (count > 1) return false;
        } else {
            l++;
            r--;
        }
    }
    return true;
}