func maxProduct(nums []int) int {
    sort.Ints(nums)
    lens := len(nums)
    return (nums[lens - 1] - 1) * (nums[lens - 2] - 1)
}