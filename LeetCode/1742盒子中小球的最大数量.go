func countBalls(lowLimit int, highLimit int) int {
	nums := make([]int, 100)
	for i := lowLimit; i <= highLimit; i++ {
		nums[calcSum(i)]++
	}
	sort.Slice(nums, func(a, b int) bool {
		return nums[a] > nums[b]
	})
	return nums[0]
}

func calcSum(num int) int {
	ans := 0
	for num > 0 {
		ans += num % 10
		num /= 10
	}
	return ans
}