//切片不能用==判等，但是数组可以用==判等
func findAnagrams(s string, p string) []int {
	lens, lenp := len(s), len(p)
	var ans []int
	if lens < lenp {
		return ans
	}
	var chs [26]int
	var chp [26]int
	for i := 0; i < lenp; i++ {
		chs[s[i]-'a']++
		chp[p[i]-'a']++
	}
	if chs == chp {
		ans = append(ans, 0)
	}
	for i := lenp; i < lens; i++ {
		chs[s[i-lenp]-'a']--
		chs[s[i]-'a']++
		if chs == chp {
			ans = append(ans, i-lenp+1)
		}
	}
	return ans
}