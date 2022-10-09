func finalValueAfterOperations(operations []string) int {
    ans := 0
    for i := 0; i < len(operations); i++ {
        if operations[i][1] == '+' {
            ans++
        } else {
            ans--
        }
    }
    return ans
}