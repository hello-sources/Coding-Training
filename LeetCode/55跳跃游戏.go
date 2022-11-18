func canJump(nums []int) bool {
	cnt := 0
	for i := 0; i <= cnt; i++ {
		if i+nums[i] > cnt {
			cnt = i + nums[i]
		}
		if cnt >= len(nums)-1 {
			return true
		}
	}
	return false
}