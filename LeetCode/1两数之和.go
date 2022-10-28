func twoSum(nums []int, target int) []int {
	set := map[int]int{}
	for k, v := range nums {
		if first, ok := set[target-v]; ok {
			return []int{first, k}
		} else {
			set[v] = k
		}
	}
	return []int{}
}