func replaceSpace(s string) string {
	var str []byte
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			str = append(str, []byte("%20")...)
		} else {
			str = append(str, s[i])
		}
	}
	return string(str)
}