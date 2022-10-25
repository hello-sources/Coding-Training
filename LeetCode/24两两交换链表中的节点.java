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
//递归解法
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cur = head.next;
        ListNode newNode = swapPairs(cur.next);
        cur.next = head;
        head.next = newNode;
        return cur;
    }
}

//虚拟头节点
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode newNode = new ListNode(0);
        newNode.next = head;
        ListNode cur = newNode;
        while (cur.next != null && cur.next.next != null) {
            ListNode temp = cur.next;
            ListNode temp1 = cur.next.next.next;
            cur.next = cur.next.next;
            cur.next.next = temp;
            temp.next = temp1;
            cur = cur.next.next;
        }
        return newNode.next;
    }
}