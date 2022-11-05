/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getHeight(root *TreeNode) int {
	if root == nil {
		return 0
	}
	leftHeight := getHeight(root.Left)
	if leftHeight == -1 {
		return -1
	}
	rightHeight := getHeight(root.Right)
	if rightHeight == -1 {
		return -1
	}
	if math.Abs(float64(rightHeight-leftHeight)) > 1 {
		return -1
	}
	return int(math.Max(float64(rightHeight), float64(leftHeight))) + 1
}

func isBalanced(root *TreeNode) bool {
	if getHeight(root) == -1 {
		return false
	}
	return true
}