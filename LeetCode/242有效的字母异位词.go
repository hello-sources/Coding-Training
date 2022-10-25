//对于不同的UnCode编码，一个字符可能对应多个字节，使用rune是为了处理多个字节的问题
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	hash := map[rune]int{}
	for _, v := range s {
		hash[v]++
	}
	for _, v := range t {
		hash[v]--
		if hash[v] < 0 {
			return false
		}
	}
	return true
}