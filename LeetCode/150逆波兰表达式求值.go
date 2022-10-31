func evalRPN(tokens []string) int {
	ans := []int{}
	for _, v := range tokens {
		if v == "+" || v == "-" || v == "*" || v == "/" {
			num1 := ans[len(ans)-1]
			ans = ans[:len(ans)-1]
			num2 := ans[len(ans)-1]
			ans = ans[:len(ans)-1]
			switch v {
			case "+":
				ans = append(ans, num1+num2)
			case "-":
				ans = append(ans, num2-num1)
			case "*":
				ans = append(ans, num1*num2)
			case "/":
				ans = append(ans, num2/num1)
			}
		} else {
			val, _ := strconv.Atoi(v)
			ans = append(ans, val)
		}
	}
	return ans[0]
}