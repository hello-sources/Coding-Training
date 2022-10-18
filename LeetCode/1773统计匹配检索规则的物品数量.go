func countMatches(items [][]string, ruleKey string, ruleValue string) int {
	ans := 0
	for i := 0; i < len(items); i++ {
		if ruleKey == "type" && items[i][0] == ruleValue {
			ans += 1
		} else if ruleKey == "color" && items[i][1] == ruleValue {
			ans += 1
		} else if ruleKey == "name" && items[i][2] == ruleValue {
			ans += 1
		}
	}
	return ans
}