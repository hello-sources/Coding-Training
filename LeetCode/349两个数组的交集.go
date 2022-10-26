func intersection(nums1 []int, nums2 []int) []int {
	set := map[int]int{}
	for _, v := range nums1 {
		set[v] = 1
	}
	var ans []int
	for _, v := range nums2 {
		// if cnt, ok := set[v]; ok && cnt > 0 {
		//     ans = append(ans, v)
		//     set[v]--
		// }
		if set[v] > 0 {
			ans = append(ans, v)
			set[v]--
		}
	}
	return ans
}