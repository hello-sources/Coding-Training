func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	sort.Ints(arr2)
	ans := 0
	for _, v := range arr1 {
		flag := true
		cur := binary_search(arr2, v)
		if cur < len(arr2) {
			if arr2[cur]-v <= d {
				flag = false
			}
		}
		if cur >= 1 && cur <= len(arr2)+1 {
			if v-arr2[cur-1] <= d {
				flag = false
			}
		}
		if flag == true {
			ans += 1
		}
	}
	return ans
}

func binary_search(arr2 []int, x int) int {
	left, right := 0, len(arr2)-1
	if arr2[right] < x {
		return right + 1
	}
	for left < right {
		mid := left + (right-left)/2
		if arr2[mid] < x {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}