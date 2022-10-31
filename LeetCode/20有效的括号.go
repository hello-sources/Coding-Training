func isValid(s string) bool {
	hash := map[byte]byte{'(': ')', '[': ']', '{': '}'}
	var sta []byte
	if len(s)%2 != 0 {
		return false
	}
	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '[' || s[i] == '{' {
			sta = append(sta, hash[s[i]])
		} else if len(sta) > 0 && sta[len(sta)-1] == s[i] {
			sta = sta[:len(sta)-1]
		} else {
			return false
		}
	}
	return len(sta) == 0
}