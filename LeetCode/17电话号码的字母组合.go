var ans []string

func letterCombinations(digits string) []string {
	if len(digits) == 0 || len(digits) > 4 {
		return nil
	}
	ans = []string{}
	nums := [10]string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	backtracking("", digits, 0, nums)
	return ans
}

func backtracking(temp string, digits string, cnt int, nums [10]string) {
	if len(temp) == len(digits) {
		ans = append(ans, temp)
		return
	}
	str := nums[digits[cnt]-'0']
	for i := 0; i < len(str); i++ {
		temp = temp + string(str[i])
		backtracking(temp, digits, cnt+1, nums)
		temp = temp[:len(temp)-1]
	}
}