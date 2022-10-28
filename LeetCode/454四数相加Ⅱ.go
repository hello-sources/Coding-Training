func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	set := map[int]int{}
	ans := 0
	for _, v1 := range nums1 {
		for _, v2 := range nums2 {
			sum := v1 + v2
			if set[sum] != 0 {
				set[sum] += 1
			} else {
				set[sum] = 1
			}
		}
	}
	for _, v1 := range nums3 {
		for _, v2 := range nums4 {
			sum := 0 - v1 - v2
			if set[sum] != 0 {
				ans += set[sum]
			}
		}
	}
	return ans
}