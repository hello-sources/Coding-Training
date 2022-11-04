/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
	var ans [][]int
	var que []*Node
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
			for i := 0; i < len(node.Children); i++ {
				que = append(que, node.Children[i])
			}
		}
		ans = append(ans, temp)
	}
	return ans
}