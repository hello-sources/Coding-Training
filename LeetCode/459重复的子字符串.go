func repeatedSubstringPattern(s string) bool {
	next := make([]int, len(s)+1)
	j := -1
	next[0] = j
	for i := 1; i < len(s); i++ {
		for j >= 0 && s[i] != s[j+1] {
			j = next[j]
		}
		if s[i] == s[j+1] {
			j++
		}
		next[i] = j
	}
	if next[len(s)-1] != -1 && len(s)%(len(s)-(next[len(s)-1]+1)) == 0 {
		return true
	}
	return false
}