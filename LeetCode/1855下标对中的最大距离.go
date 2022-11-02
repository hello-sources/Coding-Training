import "math"

func maxDistance(nums1 []int, nums2 []int) int {
	ans := 0
	for i := 0; i < len(nums1); i++ {
		left, right := i+1, len(nums2)-1
		for left <= right {
			mid := left + (right-left)/2
			if nums1[i] <= nums2[mid] {
				left = mid + 1
				ans = int(math.Max(float64(ans), float64(mid-i)))
			} else {
				right = mid - 1
			}
		}
	}
	return ans
}