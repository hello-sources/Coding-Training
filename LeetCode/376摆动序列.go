func wiggleMaxLength(nums []int) (ans int) {
	ans = 1
	pre, cur := 0, 0
	lens := len(nums)
	if lens <= 1 {
		return lens
	}
	for i := 0; i < lens-1; i++ {
		cur = nums[i+1] - nums[i]
		if (pre <= 0 && cur > 0) || (pre >= 0 && cur < 0) {
			pre = cur
			ans++
		}
	}
	return ans
}