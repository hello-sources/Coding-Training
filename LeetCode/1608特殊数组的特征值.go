func specialArray(nums []int) int {
    // sort.Ints(nums)
    sort.Sort(sort.Reverse(sort.IntSlice(nums))) //进行逆排序
    left, right := 1, len(nums)
    for left <= right {
        mid := left + (right - left) / 2
        if nums[mid - 1] >= mid {
            if mid == len(nums) || nums[mid] < mid {
                return mid
            } else {
                left = mid + 1
            }
        } else {
            right = mid - 1
        }
    }
    return -1
}