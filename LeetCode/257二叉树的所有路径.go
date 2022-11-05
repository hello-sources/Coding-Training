/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans []string

func getPath(root *TreeNode, path string) {
	pathL := path
	pathL += strconv.Itoa(root.Val)
	if root.Left == nil && root.Right == nil {
		ans = append(ans, pathL)
		return
	}
	pathL += "->"
	if root.Left != nil {
		getPath(root.Left, pathL)
	}
	if root.Right != nil {
		getPath(root.Right, pathL)
	}
}

func binaryTreePaths(root *TreeNode) []string {
	ans = []string{}
	if root == nil {
		return ans
	}
	var path string
	getPath(root, path)
	return ans
}