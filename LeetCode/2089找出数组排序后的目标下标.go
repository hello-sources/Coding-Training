func targetIndices(nums []int, target int) []int {
	ans := []int{}
	sort.Ints(nums)
	for k, v := range nums {
		if v == target {
			ans = append(ans, k)
		}
	}
	return ans
}