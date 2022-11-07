/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findMode(root *TreeNode) []int {
	sta := []*TreeNode{}
	cur := root
	var pre *TreeNode
	cnt, maxCnt := 0, 0
	ans := []int{}
	for cur != nil || len(sta) > 0 {
		if cur != nil {
			sta = append(sta, cur)
			cur = cur.Left
		} else {
			cur = sta[len(sta)-1]
			sta = sta[:len(sta)-1]
			if pre == nil { //第一个节点
				cnt = 1
			} else if pre.Val == cur.Val { //与前一个节点相同
				cnt++
			} else { //与前一个节点不同
				cnt = 1
			}
			if cnt == maxCnt {
				ans = append(ans, cur.Val)
			}
			if cnt > maxCnt {
				maxCnt = cnt
				ans = []int{}
				ans = append(ans, cur.Val)
			}
			pre = cur
			cur = cur.Right
		}
	}
	return ans
}

/*
	整体框架是使用栈模拟二叉树的中序遍历，也就是迭代法
	加上两个控制条件，一个是统计频率，一个统计最大频率
	当cnt == maxCnt 时候，表示访问到了一个值，但是也有可能maxCnt还会变大
	因此如果cnt > maxCnt需要更新maxCnt，然后清空切片，再把数加进去
*/