var ans [][]int

func combinationSum3(k int, n int) [][]int {
	ans = [][]int{}
	backtracking(1, 0, k, n, []int{})
	return ans
}

func backtracking(left int, sum int, k int, n int, path []int) {
	if len(path) == k && sum == n {
		temp := make([]int, k)
		copy(temp, path)
		ans = append(ans, temp)
		return
	}
	for i := left; i <= 9; i++ {
		sum += i
		path = append(path, i)
		backtracking(i+1, sum, k, n, path)
		path = path[:len(path)-1]
		sum -= i
	}
	return
}	