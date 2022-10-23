func spiralOrder(matrix [][]int) []int {
	m, n := len(matrix), len(matrix[0])
	var ans []int
	left, right := 0, n-1
	top, buttom := 0, m-1
	num := m * n
	for num > 0 {
		for i := left; i <= right && num > 0; i++ {
			ans = append(ans, matrix[top][i])
			num--
		}
		top++
		for i := top; i <= buttom && num > 0; i++ {
			ans = append(ans, matrix[i][right])
			num--
		}
		right--
		for i := right; i >= left && num > 0; i-- {
			ans = append(ans, matrix[buttom][i])
			num--
		}
		buttom--
		for i := buttom; i >= top && num > 0; i-- {
			ans = append(ans, matrix[i][left])
			num--
		}
		left++
	}
	return ans
}