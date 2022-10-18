func arithmeticTriplets(nums []int, diff int) int {
	cnt := 0
	for i := 0; i < len(nums)-2; i++ {
		for j := 1; j < len(nums)-1; j++ {
			for k := 2; k < len(nums); k++ {
				if nums[k]-nums[j] == diff &&
					nums[j]-nums[i] == diff {
					cnt++
				}
			}
		}
	}
	return cnt
}

/*-----------------------哈希表----------------------*/
func arithmeticTriplets(nums []int, diff int) (ans int) {
	set := map[int]bool{}
	for _, v := range nums {
		set[v] = true
	}
	for _, v := range nums {
		if set[v-diff] && set[v+diff] {
			ans++
		}
	}
	return
}