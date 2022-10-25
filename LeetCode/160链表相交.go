/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	curA, curB := headA, headB
	cntA, cntB := 0, 0
	for curA != nil {
		curA = curA.Next
		cntA++
	}
	for curB != nil {
		curB = curB.Next
		cntB++
	}
	curA, curB = headA, headB
	if cntA < cntB {
		cntA, cntB = cntB, cntA
		curA, curB = curB, curA
	}
	for cal := cntA - cntB; cal > 0; cal-- {
		curA = curA.Next
	}
	for curA != nil {
		if curA == curB {
			return curA
		}
		curA = curA.Next
		curB = curB.Next
	}
	return nil
}