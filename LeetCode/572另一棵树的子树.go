/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/*
 还有一种思想：将两个树按根左右将元素扫描到两个数组中，看数组A，B有没有包含关系，读者可以思考往复杂了应该怎么些写
*/
func isSubtree(s *TreeNode, t *TreeNode) bool {
	if s == nil {
		return false
	}
	return isSameTree(s, t) || isSubtree(s.Left, t) || isSubtree(s.Right, t)	
}

func isSameTree(s, t *TreeNode) bool {
	if s == nil && t == nil {
		return true
	}
	if s == nil || t == nil {
		return false
	}
	return s.Val == t.Val && isSameTree(s.Left, t.Left) && isSameTree(s.Right, t.Right)
}