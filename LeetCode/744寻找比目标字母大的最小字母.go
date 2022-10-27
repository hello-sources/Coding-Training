func nextGreatestLetter(letters []byte, target byte) byte {
	if target >= letters[len(letters)-1] {
		return letters[0]
	}
	left := sort.Search(len(letters)-1, func(i int) bool {
		return letters[i] > target
	})
	return letters[left]
}