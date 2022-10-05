func heightChecker(heights []int) int {
    var backup = make([]int, len(heights))
    copy(backup, heights)
    // sort.Sort(sort.IntSlice(backup))
    sort.Ints(backup)
    cnt := 0
    for i := 0; i < len(backup); i++ {
        if heights[i] != backup[i] {
            cnt++
        }
    }
    return cnt
}