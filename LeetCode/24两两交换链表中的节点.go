/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	dummyHead := &ListNode{}
	dummyHead.Next = head
	cur := dummyHead
	for cur.Next != nil && cur.Next.Next != nil {
		temp := cur.Next
		temp1 := cur.Next.Next.Next
		cur.Next = cur.Next.Next
		cur.Next.Next = temp
		temp.Next = temp1
		cur = cur.Next.Next
	}
	return dummyHead.Next
}