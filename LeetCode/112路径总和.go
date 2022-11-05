/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func judge(root *TreeNode, sum int) bool {
	if root.Left == nil && root.Right == nil && sum == 0 {
		return true //叶节点，且路径和等于target
	}
	if root.Left == nil && root.Right == nil {
		return false // 叶节点，但是路径和不等于target
	}
	if root.Left != nil {
		sum -= root.Left.Val
		if judge(root.Left, sum) {
			return true
		}
		sum += root.Left.Val
	}
	if root.Right != nil {
		sum -= root.Right.Val
		if judge(root.Right, sum) {
			return true
		}
		sum += root.Right.Val
	}
	return false
}

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	return judge(root, targetSum-root.Val)
}