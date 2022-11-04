/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func averageOfLevels(root *TreeNode) []float64 {
	var ans []float64
	var que []*TreeNode
	if root != nil {
		que = append(que, root)
	}
	for len(que) > 0 {
		size := len(que)
		cnt := size
		sum := 0.0
		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]
			sum += float64(node.Val)
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
		ans = append(ans, sum/float64(cnt))
	}
	return ans
}