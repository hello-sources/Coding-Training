func maxAscendingSum(nums []int) int {
	var ans, sum = 0, 0
	for i := 0; i < len(nums); i++ {
		if i != 0 && nums[i-1] < nums[i] {
			sum += nums[i]
		} else {
			sum = nums[i]
		}
		ans = int(math.Max(float64(ans), float64(sum)))
	}
	return ans
}