/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	return build(nums, 0, len(nums)-1)
}

func build(nums []int, left int, right int) *TreeNode {
	if left > right {
		return nil
	}
	mid := left + (right-left)/2
	node := &TreeNode{
		Val:   nums[mid],
		Left:  build(nums, left, mid-1),
		Right: build(nums, mid+1, right)}
	return node
}