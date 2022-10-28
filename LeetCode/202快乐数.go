func isHappy(n int) bool {
	set := map[int]bool{}
	for n != 1 && !set[n] {
		set[n] = true
		temp := func(x int) int {
			sum := 0
			for x > 0 {
				temp := x % 10
				sum += temp * temp
				x /= 10
			}
			return sum
		}
		n = temp(n)
	}
	return n == 1
}