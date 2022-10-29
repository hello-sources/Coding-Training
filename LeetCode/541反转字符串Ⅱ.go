func reverseStr(s string, k int) string {
	str := []byte(s)
	for i := 0; i < len(s); i += 2 * k {
		left := i
		right := int(math.Min(float64(left+k-1), float64(len(s)-1)))
		for left < right {
			str[left], str[right] = str[right], str[left]
			left++
			right--
		}
	}
	return string(str)
}