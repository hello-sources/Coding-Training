func maxSubArray(nums []int) (ans int) {
	dp := make([]int, len(nums))
	dp[0] = nums[0]
	ans = nums[0]
	for i := 1; i < len(nums); i++ {
		dp[i] = int(math.Max(float64(dp[i-1]+nums[i]), float64(nums[i])))
		if dp[i] > ans {
			ans = dp[i]
		}
	}
	return
}