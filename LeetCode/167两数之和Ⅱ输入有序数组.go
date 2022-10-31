func twoSum(numbers []int, target int) []int {
	hash := make(map[int]int, len(numbers))
	for k, v := range numbers {
		hash[v] = k
	}
	for k, v := range numbers {
		if val, ok := hash[target-v]; ok {
			return []int{k + 1, val + 1}
		}
	}
	return []int{0, 0}
}