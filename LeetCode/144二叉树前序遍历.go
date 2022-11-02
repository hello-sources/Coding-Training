/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preOrder(root *TreeNode, ans *[]int) {
	if root == nil {
		return
	}
	*ans = append(*ans, root.Val)
	preOrder(root.Left, ans)
	preOrder(root.Right, ans)
}

func preorderTraversal(root *TreeNode) []int {
	var ans []int
	preOrder(root, &ans)
	return ans
}

// 传入切片的时候，需要传入引用，因为Go语言采用的是值传递，
// 如果想在传值过程中保持值的不变，则使用引用，然后函数加上取值符

/**
 * 非递归，使用栈进行模拟
 */
func preorderTraversal(root *TreeNode) (ans []int) {
	sta := []*TreeNode{}
	if root == nil {
		return
	}
	sta = append(sta, root)
	for len(sta) > 0 {
		pre := sta[len(sta)-1]
		sta = sta[:len(sta)-1]
		ans = append(ans, pre.Val)
		if pre.Left != nil {
			sta = append(sta, pre.Left)
		}
		if pre.Right != nil {
			sta = append(sta, pre.Right)
		}
	}
	return
}