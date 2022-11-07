/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func calc(root *TreeNode, sum *int) {
	if root == nil {
		return
	}
	calc(root.Right, sum)
	*sum += root.Val
	root.Val = *sum
	calc(root.Left, sum)
}

func convertBST(root *TreeNode) *TreeNode {
	sum := 0
	calc(root, &sum)
	return root
}