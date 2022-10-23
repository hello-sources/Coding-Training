func generateMatrix(n int) [][]int {
	ans := make([][]int, n)
	left, right := 0, n-1
	top, botton := 0, n-1
	for i := 0; i < n; i++ {
		ans[i] = make([]int, n)
	}
	num := 1
	for num <= n*n {
		for i := left; i <= right; i++ {
			ans[top][i] = num
			num++
		}
		top++
		for i := top; i <= botton; i++ {
			ans[i][right] = num
			num++
		}
		right--
		for i := right; i >= left; i-- {
			ans[botton][i] = num
			num++
		}
		botton--
		for i := botton; i >= top; i-- {
			ans[i][left] = num
			num++
		}
		left++
	}
	return ans
}