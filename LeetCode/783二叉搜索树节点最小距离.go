/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDiffInBST(root *TreeNode) int {
	ans := 100005
	var sta []*TreeNode
	if root == nil {
		return 0
	}
	cur := root
	var pre *TreeNode
	for cur != nil || len(sta) > 0 {
		if cur != nil {
			sta = append(sta, cur)
			cur = cur.Left
		} else {
			cur = sta[len(sta)-1]
			sta = sta[:len(sta)-1]
			if pre != nil {
				temp := int(math.Abs(float64(pre.Val - cur.Val)))
				ans = int(math.Min(float64(temp), float64(ans)))
			}
			pre = cur
			cur = cur.Right
		}
	}
	return ans
}