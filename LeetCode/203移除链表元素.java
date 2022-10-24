/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode p = new ListNode();
        ListNode q = new ListNode();
        p.next = head;
        q = p;
        while (q != null && q.next != null) {
            if (q.next.val == val) {
                q.next = q.next.next;
            } else {
                q = q.next;
            }
        }
        return p.next;
    }
}