func customSortString(order string, s string) (ans string) {
	str := []byte(s)
	for i := 0; i < len(order); i++ {
		for j := 0; j < len(str); j++ {
			if str[j] == order[i] {
				ans += string(str[j])
				str[j] = '.'
			}
		}
	}
	for i := 0; i < len(str); i++ {
		if str[i] == '.' {
			continue
		}
		ans += string(str[i])
	}
	return
}