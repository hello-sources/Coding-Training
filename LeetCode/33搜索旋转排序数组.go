func search(nums []int, target int) int {
	size := len(nums)
	if size == 0 {
		return -1
	} else if size == 1 {
		if nums[0] == target {
			return 0
		}
		return -1
	}
	left, right := 0, size-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		}
		if nums[0] <= nums[mid] {
			if nums[0] <= target && target < nums[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else {
			if nums[mid] < target && target <= nums[size-1] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}
	return -1
}