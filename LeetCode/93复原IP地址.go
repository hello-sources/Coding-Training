func restoreIpAddresses(s string) []string {
	var ans []string
	var ip []string
	backtracking(s, 0, &ans, ip)
	return ans
}

func backtracking(s string, ind int, ans *[]string, ip []string) {
	if ind == len(s) && len(ip) == 4 {
		temp := ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]
		*ans = append(*ans, temp)
		return
	}
	for i := ind; i < len(s); i++ {
		ip = append(ip, s[ind:i+1])
		// 表示当前的一个字段长度属于正常范畴,且ip字段少于4,且该字段是正常
		if i-ind+1 <= 3 && len(ip) <= 4 && isValid(s, ind, i) {
			backtracking(s, i+1, ans, ip)
		} else {
			return
		}
		ip = ip[:len(ip)-1]
	}
	return
}

func isValid(s string, left int, right int) bool {
	num, _ := strconv.Atoi(s[left : right+1])
	if right-left+1 > 1 && s[left] == '0' {
		return false
	}
	if num > 255 {
		return false
	}
	return true
}