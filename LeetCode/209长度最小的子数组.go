func minSubArrayLen(target int, nums []int) int {
	int_max := 2 << 31
	ans := int_max
	start, sum, length := 0, 0, 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		for sum >= target {
			length = i - start + 1
			if ans >= length {
				ans = length
			}
			sum -= nums[start]
			start++
		}
	}
	if ans == int_max {
		return 0
	}
	return ans
}