/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSameTree(p *TreeNode, q *TreeNode) bool {
	var quep []*TreeNode
	var queq []*TreeNode
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	quep = append(quep, p)
	queq = append(queq, q)
	for len(quep) > 0 && len(queq) > 0 {
		node1, node2 := quep[0], queq[0]
		quep, queq = quep[1:], queq[1:]
		if node1.Val != node2.Val {
			return false
		}
		left1, right1 := node1.Left, node1.Right
		left2, right2 := node2.Left, node2.Right
		if (left1 == nil && left2 != nil) || (left1 != nil && left2 == nil) {
			return false
		}
		if (right1 == nil && right2 != nil) || (right1 != nil && right2 == nil) {
			return false
		}
		if left1 != nil {
			quep = append(quep, left1)
		}
		if right1 != nil {
			quep = append(quep, right1)
		}
		if left2 != nil {
			queq = append(queq, left2)
		}
		if right2 != nil {
			queq = append(queq, right2)
		}
	}
	return len(quep) == 0 && len(queq) == 0
}