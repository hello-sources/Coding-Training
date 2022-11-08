func countConsistentStrings(allowed string, words []string) (cnt int) {
	num := [26]bool{}
	for _, v := range allowed {
		num[v-'a'] = true
	}
	check := func(s string) bool {
		for _, v := range s {
			if num[v-'a'] == false {
				return false
			}
		}
		return true
	}
	for _, v := range words {
		if check(v) {
			cnt++
		}
	}
	return cnt
}

/*
	位运算妙招，先把每一位左移减去'a'，每遍历一个位置就做一次或运算
	然后再根据 words 中的每一个word进行位运算，比较结果即可
*/
func countConsistentStrings(allowed string, words []string) (cnt int) {
	mask := 0
	for _, v := range allowed {
		mask |= 1 << (v - 'a')
	}
	for _, word := range words {
		temp := 0
		for _, v := range word {
			temp |= 1 << (v - 'a')
		}
		if temp|mask == mask {
			cnt++
		}
	}
	return
}