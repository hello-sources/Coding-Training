func searchMatrix(matrix [][]int, target int) bool {
	row := sort.Search(len(matrix), func(i int) bool { return matrix[i][0] > target }) - 1
	if row < 0 {
		return false
	}
	col := sort.SearchInts(matrix[row], target)
	return col < len(matrix[0]) && matrix[row][col] == target
}

/*
	sort.Search是二分查找，go语言封装好的
	sort.SearchInts表示查找对应的元素，如果没有则返回要插入的位置
	
	index := sort.Search(n int,f func(i int) bool) int
	函数使用二分查找的方法，会从[0, n)中取出一个值index，index为[0, n)中最小的使函数f(index)为True的值，
	并且f(index+1)也为True。如果无法找到该index值，则该方法为返回n。	
*/