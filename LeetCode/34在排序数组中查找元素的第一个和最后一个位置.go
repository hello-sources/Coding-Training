func searchRange(nums []int, target int) []int {
	var ans []int
	start, end := -1, -1
	flag := true
	for k, num := range nums {
		if num == target && flag {
			start = k
			flag = false
		}
		if num == target && !flag {
			end = k
		}
	}
	ans = append(ans, start)
	ans = append(ans, end)
	return ans
}