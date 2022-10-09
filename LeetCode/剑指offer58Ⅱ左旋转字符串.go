func reverseLeftWords(s string, n int) string {
	for i := 0; i < n; i++ {
		s += string(s[i])
	}
	s = s[n:]
	return s
}

// 引入byte数组进行字符的操作
func reverseLeftWords(s string, n int) string {
	ans := []byte(s)
	var temp []byte
	for i := 0; i < n; i++ {
		temp = append(temp, ans[i])
	}
	ans = append(ans[n:len(s)], temp...)
	return string(ans)
}