/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) (ans []int) {
	sta := []*TreeNode{}
	var pre *TreeNode
	for root != nil || len(sta) > 0 {
		for root != nil {
			sta = append(sta, root)
			root = root.Left
		}
		root = sta[len(sta)-1]
		sta = sta[:len(sta)-1]
		if root.Right == nil || root.Right == pre {
			ans = append(ans, root.Val)
			pre = root
			root = nil
		} else {
			sta = append(sta, root)
			root = root.Right
		}
	}
	return
}