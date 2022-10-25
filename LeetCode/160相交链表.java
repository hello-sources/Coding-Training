/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
         ListNode p = headA;
        ListNode q = headB;
        int cntA = 0, cntB = 0;
        while (p != null) {
            p = p.next;
            cntA++;
        }
        while (q != null) {
            q = q.next;
            cntB++;
        }
        p = headA;
        q = headB;
        if (cntB > cntA) {
            int temp = cntA;
            cntA = cntB;
            cntB = temp;
            ListNode sw = p;
            p = q;
            q = sw;
        }
        int cal = cntA - cntB;
        while (cal-- > 0) {
            p = p.next;
        }
        while (p != null) {
            if (p == q) {
                return p;
            }
            p = p.next;
            q = q.next;
        }
        return null;
    }
}