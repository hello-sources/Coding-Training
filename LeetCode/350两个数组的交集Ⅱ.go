func intersect(nums1 []int, nums2 []int) []int {
	if len(nums1) > len(nums2) {
		intersect(nums2, nums1)
	}
	hash := map[int]int{}
	var ans []int
	for _, v := range nums1 {
		hash[v]++
	}
	for _, v := range nums2 {
		cnt := hash[v]
		if cnt > 0 {
			ans = append(ans, v)
			cnt--
			if cnt > 0 {
				hash[v] = cnt
			} else {
				delete(hash, v)
			}
		}
	}
	return ans
}