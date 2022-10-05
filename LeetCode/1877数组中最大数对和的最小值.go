const INT_MAX = int(^uint32((0)) >> 1)
func minPairSum(nums []int) int {
    sort.Sort(sort.IntSlice(nums))
    ans := 0
    for i := 0; i < len(nums) / 2; i++ {
        ans = int(math.Max(float64(nums[i] + nums[len(nums) - 1 - i]), float64(ans)))
    }
    return ans
}