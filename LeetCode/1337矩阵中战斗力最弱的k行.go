func kWeakestRows(mat [][]int, k int) []int {
	var cnt [][]int
	for i := 0; i < len(mat); i++ {
		left, right := 0, len(mat[i])-1
		for left <= right {
			mid := left + (right-left)/2
			if mat[i][mid] == 0 {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
		cnt = append(cnt, []int{left, i})
	}
	sort.Slice(cnt, func(a, b int) bool {
		if cnt[a][0] == cnt[b][0] {
			return cnt[a][1] < cnt[b][1]
		}
		return cnt[a][0] < cnt[b][0]
	})
	var ans []int
	for i := 0; i < k; i++ {
		ans = append(ans, cnt[i][1])
	}
	return ans
}

/*
	1、自定义排序sort.Slice(待排序数组-高维，func(a, b int) bool {
		参数必须为int类型，返回值是bool类型
	})
	2、高维切片添加数据的时候可以使用
		var res [][]int
		res = append(res, []int{a, b, c})
		res[i] = append(res[i], a, b, c)
*/