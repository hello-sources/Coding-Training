/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	var sta []*TreeNode
	cur := root
	var pre *TreeNode
	for cur != nil || len(sta) > 0 {
		if cur != nil {
			sta = append(sta, cur)
			cur = cur.Left
		} else {
			cur = sta[len(sta)-1]
			sta = sta[:len(sta)-1]
			if pre != nil && pre.Val >= cur.Val {
				return false
			}
			pre = cur
			cur = cur.Right
		}
	}
	return true
}