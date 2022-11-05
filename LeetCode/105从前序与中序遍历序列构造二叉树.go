/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}
	rootVal := preorder[0]
	ind := 0
	for ind < len(inorder) {
		if inorder[ind] == rootVal {
			break
		}
		ind++
	}
	root := &TreeNode{
		Val:   rootVal,
		Left:  buildTree(preorder[1:ind+1], inorder[:ind]),
		Right: buildTree(preorder[ind+1:], inorder[ind+1:])}
	return root
}