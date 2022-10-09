/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 需要判断节点是否为nil类型的
func deleteNode(node *ListNode) {
	for node != nil {
		node.Val = node.Next.Val
		if node.Next.Next == nil {
			node.Next = nil
		}
		node = node.Next
	}
}

// golang函数的传递都为值传递
//如果直接进行node = node.Next，并不会修改原先数据，故无效
func deleteNode(node *ListNode) {
	*node = *node.Next
}