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
		for i := 0; i < size; i++ {
            if i + 1 < size {
                que[i].Next = que[i + 1]
            }
			if que[i].Left != nil {
				que = append(que, que[i].Left)
			}
			if que[i].Right != nil {
				que = append(que, que[i].Right)
			}
		}
        que = que[size:]
	}
    return root
}