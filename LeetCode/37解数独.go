func solveSudoku(board [][]byte) {
	backtracking(board)
	return
}

func backtracking(board [][]byte) bool {
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] != '.' {
				continue
			}
			for ch := '1'; ch <= '9'; ch++ {
				if isValid(i, j, byte(ch), board) {
					board[i][j] = byte(ch)
					if backtracking(board) {
						return true
					}
					board[i][j] = '.'
				}
			}
			return false
		}
	}
	return true
}

func isValid(row, col int, ch byte, board [][]byte) bool {
	for i := 0; i < 9; i++ {
		if board[row][i] == ch {
			return false
		}
	}
	for i := 0; i < 9; i++ {
		if board[i][col] == ch {
			return false
		}
	}

	startrow := (row / 3) * 3
	startcol := (col / 3) * 3
	for i := startrow; i < startrow+3; i++ {
		for j := startcol; j < startcol+3; j++ {
			if board[i][j] == ch {
				return false
			}
		}
	}
	return true
}