/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func constructMaximumBinaryTree(nums []int) *TreeNode {
	return calc(nums, 0, len(nums))
}

func calc(nums []int, left int, right int) *TreeNode {
	if left >= right {
		return nil
	}
	maxInd := left
	for i := maxInd + 1; i < right; i++ {
		if nums[maxInd] < nums[i] {
			maxInd = i
		}
	}
	node := &TreeNode{
		Val:   nums[maxInd],
		Left:  calc(nums, left, maxInd),
		Right: calc(nums, maxInd+1, right)}
	return node
}