/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
	var que []*Node
	if root != nil {
		que = append(que, root)
	}
	for len(que) > 0 {
		size := len(que)
		tmp := que
		que = nil
		for i := 0; i < size; i++ {
			if i+1 < len(tmp) {
				tmp[i].Next = tmp[i+1]
			}
			if tmp[i].Left != nil {
				que = append(que, tmp[i].Left)
			}
			if tmp[i].Right != nil {
				que = append(que, tmp[i].Right)
			}
		}
	}
	return root
}