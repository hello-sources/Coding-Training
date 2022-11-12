var ans [][]string

func solveNQueens(n int) [][]string {
	ans = [][]string{}
	chs := make([][]string, n)
	for i := 0; i < n; i++ {
		chs[i] = make([]string, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			chs[i][j] = "."
		}
	}
	backtracking(n, 0, chs)
	return ans
}

func backtracking(n int, row int, chs [][]string) {
	if row == n {
		temp := make([]string, n)
		for i, rowStr := range chs {
			temp[i] = strings.Join(rowStr, "")
		}
		ans = append(ans, temp)
		return
	}
	for i := 0; i < n; i++ {
		if isValid(row, i, chs, n) {
			chs[row][i] = "Q"
			backtracking(n, row+1, chs)
			chs[row][i] = "."
		}
	}
}

func isValid(row, col int, chs [][]string, n int) bool {
	for i := 0; i < row; i++ {
		if chs[i][col] == "Q" {
			return false
		}
	}
	for i, j := row-1, col-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if chs[i][j] == "Q" {
			return false
		}
	}
	for i, j := row-1, col+1; i >= 0 && j < n; i, j = i-1, j+1 {
		if chs[i][j] == "Q" {
			return false
		}
	}
	return true
}