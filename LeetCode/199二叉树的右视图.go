/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) []int {
	var ans []int
	var que []*TreeNode
	if root != nil {
		que = append(que, root)
	}
	for len(que) > 0 {
		size := len(que)
		var temp []int
		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]
			temp = append(temp, node.Val)
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
		ans = append(ans, temp[len(temp)-1])
	}
	return ans
}