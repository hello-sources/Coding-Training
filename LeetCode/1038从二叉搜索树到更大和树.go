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
	root.Val += *sum
	*sum = root.Val
	calc(root.Left, sum)
}

func bstToGst(root *TreeNode) *TreeNode {
	sum := 0
	calc(root, &sum)
	return root
}