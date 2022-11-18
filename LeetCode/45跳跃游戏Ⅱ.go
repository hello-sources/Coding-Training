func jump(nums []int) (ans int) {
	if len(nums) == 1 {
		return 0
	}
	ans = 0
	cur, next := 0, 0
	for i := 0; i <= cur && cur < len(nums)-1; i++ {
		if i+nums[i] > next {
			next = i + nums[i]
		}
		if i == cur {
			ans++
			cur = next
		}
	}
	return
}