// sort.Slice对切片进行排序，需要重写compare方法
func groupAnagrams(strs []string) [][]string {
	hash := map[string][]string{}
	for _, v := range strs {
		s := []byte(v)
		sort.Slice(s, func(i, j int) bool {
			return s[i] < s[j]
		})
		str := string(s)
		hash[str] = append(hash[str], v)
	}
	ans := make([][]string, 0, len(hash))
	for _, v := range hash {
		ans = append(ans, v)
	}
	return ans
}