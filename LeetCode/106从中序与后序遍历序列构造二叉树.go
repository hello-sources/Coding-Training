/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(inorder) < 1 || len(postorder) < 1 {
		return nil
	}
	rootVal := postorder[len(postorder)-1]
	left := getRootIndex(inorder, rootVal)
	root := &TreeNode{Val: rootVal,
		Left:  buildTree(inorder[:left], postorder[:left]),
		Right: buildTree(inorder[left+1:], postorder[left:len(postorder)-1])}
	return root
}

func getRootIndex(inorder []int, target int) (ind int) {
	for i := 0; i < len(inorder); i++ {
		if target == inorder[i] {
			return i
		}
	}
	return -1
}