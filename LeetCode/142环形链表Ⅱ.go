/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if slow == fast {
			ind1, ind2 := fast, head
			for ind1 != ind2 {
				ind1 = ind1.Next
				ind2 = ind2.Next
			}
			return ind1
		}
	}
	return nil
}