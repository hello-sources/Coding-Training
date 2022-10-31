func checkIfExist(arr []int) bool {
	hash := map[int]int{}
	for k, v := range arr {
		hash[v] = k
	}
	for k, v := range arr {
		if val, ok := hash[v*2]; ok && val != k {
			return true
		}
	}
	return false
}