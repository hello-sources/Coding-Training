func sortedSquares(nums []int) []int {
	for k, v := range nums {
		nums[k] = v * v
	}
	sort.Ints(nums)
	return nums
}

/*
	双指针
*/
func sortedSquares(nums []int) []int {
	length := len(nums)
	ans := make([]int, length)
	i := 0
	j, k := length-1, length-1
	for i <= j {
		if nums[i]*nums[i] <= nums[j]*nums[j] {
			ans[k] = nums[j] * nums[j]
			j--
		} else {
			ans[k] = nums[i] * nums[i]
			i++
		}
		k--
	}
	return ans
}