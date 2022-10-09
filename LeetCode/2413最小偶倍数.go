func smallestEvenMultiple(n int) int {
    if n >= 2 && n % 2 == 0 {
        return n
    } else if n == 1 {
        return 2
    }
    return 2 * n
}