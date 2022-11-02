/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inOrder(root *TreeNode, ans *[]int) {
	if root == nil {
		return
	}
	inOrder(root.Left, ans)
	*ans = append(*ans, root.Val)
	inOrder(root.Right, ans)
}

func inorderTraversal(root *TreeNode) (ans []int) {
	inOrder(root, &ans)
	return ans
}

/**
 * 用栈递归
 */
func inorderTraversal(root *TreeNode) (ans []int) {
	sta := []*TreeNode{}
	if root == nil {
		return
	}
	for root != nil || len(sta) > 0 {
		if root != nil {
			sta = append(sta, root)
			root = root.Left
		} else {
			root = sta[len(sta)-1]
			sta = sta[:len(sta)-1]
			ans = append(ans, root.Val)
			root = root.Right
		}
	}
	return
}