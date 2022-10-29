func fourSum(nums []int, target int) [][]int {
	var ans [][]int
	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 && nums[i] > target {
			break
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] > 0 && nums[i]+nums[j] > target {
				break
			}
			if j > i+1 && nums[j-1] == nums[j] {
				continue
			}
			left, right := j+1, len(nums)-1
			for left < right {
				temp := nums[i] + nums[j] + nums[left] + nums[right]
				if temp < target {
					left++
				} else if temp > target {
					right--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[left], nums[right]})
					for left < right && nums[left] == nums[left+1] {
						left++
					}
					for left < right && nums[right-1] == nums[right] {
						right--
					}
					left++
					right--
				}
			}
		}
	}
	return ans
}