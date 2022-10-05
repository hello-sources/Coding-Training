func smallerNumbersThanCurrent(nums []int) []int {
    var ans = make([]int, len(nums))
    cnt := 0
    for k, v := range nums {
        cnt = 0
        for k1, v1 := range nums {
            if k1 != k && v > v1 {
                cnt++
            }
        }
        ans[k] = cnt
    }
    return ans
}