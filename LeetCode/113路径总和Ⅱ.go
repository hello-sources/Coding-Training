/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, targetSum int) [][]int {
	ans := make([][]int, 0)
	calc(root, &ans, new([]int), targetSum)
	return ans
}

func calc(root *TreeNode, ans *[][]int, path *[]int, sum int) {
	if root == nil {
		return
	}
	sum -= root.Val
	*path = append(*path, root.Val)
	if root.Left == nil && root.Right == nil && sum == 0 {
		temp := make([]int, len(*path))
		for i := 0; i < len(*path); i++ {
			temp[i] = (*path)[i]
		}
		*ans = append(*ans, temp)
	}
	calc(root.Left, ans, path, sum)
	calc(root.Right, ans, path, sum)
	*path = (*path)[:len(*path)-1]
	return
}

/*
	Go传值，不是传引用
	new 使用来分配内存，并且返回内存地址，不必指定长度
	make 是创建channel map 和切片的内存分配，指定长度
*/