/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var maxDepth int
var ans int

func calc(root *TreeNode, depth int) {
	if root.Left == nil && root.Right == nil {
		if depth > maxDepth {
			maxDepth = depth
			ans = root.Val
		}
		return
	}
	if root.Left != nil {
		depth++
		calc(root.Left, depth)
		depth--
	}
	if root.Right != nil {
		depth++
		calc(root.Right, depth)
		depth--
	}
	return
}

func findBottomLeftValue(root *TreeNode) int {
	if root.Left == nil && root.Right == nil {
		return root.Val
	}
	calc(root, maxDepth)
	return ans
}

/*
	递归三个步骤
	1、找出递归参数、递归函数返回值
	2、确定终止条件
	3、确定单层循环逻辑
*/