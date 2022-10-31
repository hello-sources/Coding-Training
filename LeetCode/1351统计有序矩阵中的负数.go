func countNegatives(grid [][]int) int {
	cnt := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] < 0 {
				cnt++
			}
		}
	}
	return cnt
}