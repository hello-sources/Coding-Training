func findMin(nums []int) int {
	size := len(nums)
	if size == 1 {
		return nums[0]
	}
	left, right := 0, size-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[0] <= nums[mid] && nums[mid] > nums[size-1] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return nums[left]
}