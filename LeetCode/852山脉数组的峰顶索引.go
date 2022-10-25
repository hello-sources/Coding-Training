func peakIndexInMountainArray(arr []int) int {
	left, right := 1, len(arr)-2
	ind := 0
	for left <= right {
		mid := left + (right-left)/2
		if arr[mid] > arr[mid+1] {
			ind = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return ind
}