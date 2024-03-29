/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return root
	}
	for root != nil {
		if root.Val < val {
			root = root.Right
		} else if root.Val > val {
			root = root.Left
		} else {
			return root
		}
	}
	return nil
}