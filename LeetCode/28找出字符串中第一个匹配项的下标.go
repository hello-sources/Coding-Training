func strStr(haystack string, needle string) int {
	next := make([]int, len(needle))
	reverse(needle, next)
	j := -1
	for i := 0; i < len(haystack); i++ {
		for j >= 0 && haystack[i] != needle[j+1] {
			j = next[j]
		}
		if haystack[i] == needle[j+1] {
			j++
		}
		if j == len(needle)-1 {
			return i - j
		}
	}
	return -1
}

func reverse(needle string, next []int) {
	j := -1
	next[0] = j
	for i := 1; i < len(needle); i++ {
		for j >= 0 && needle[i] != needle[j+1] {
			j = next[j]
		}
		if needle[i] == needle[j+1] {
			j++
		}
		next[i] = j
	}
}