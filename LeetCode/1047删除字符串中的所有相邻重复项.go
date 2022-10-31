func removeDuplicates(s string) string {
	str := []byte{}
	top := 0
	for i := 0; i < len(s); i++ {
		if top > 0 && str[top-1] == s[i] {
			str = str[:top-1]
			top--
		} else {
			str = append(str, s[i])
			top++
		}
	}
	return string(str)
}