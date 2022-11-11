var ans [][]string
var path []string

func partition(s string) [][]string {
	ans = [][]string{}
	path = []string{}
	backtrack(0, s)
	return ans
}

func backtrack(ind int, s string) {
	if ind >= len(s) {
		temp := make([]string, len(path))
		copy(temp, path)
		ans = append(ans, temp)
		return
	}
	for i := ind; i < len(s); i++ {
		if isValid(s, ind, i) {
			str := s[ind : i+1]
			path = append(path, str)
		} else {
			continue
		}
		backtrack(i+1, s)
		path = path[:len(path)-1]
	}
	return
}

func isValid(s string, left int, right int) bool {
	i, j := left, right
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}