func maxProductDifference(nums []int) int {
    sort.Sort(sort.Reverse(sort.IntSlice(nums)))
    return nums[0] * nums[1] - nums[len(nums) - 1] * nums[len(nums) - 2]
}