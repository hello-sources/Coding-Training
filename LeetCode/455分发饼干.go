func findContentChildren(g []int, s []int) (ans int) {
	sort.Ints(g)
	sort.Ints(s)
	for i := 0; i < len(g); i++ {
		for j := 0; j < len(s); j++ {
			if s[j] >= g[i] {
				ans++
				s[j] = 0
				break
			}
		}
	}
	return
}

func findContentChildren(g []int, s []int) (ans int) {
	sort.Ints(g)
	sort.Ints(s)
	ind := len(s) - 1
	for i := len(g) - 1; i >= 0; i-- {
		if ind >= 0 && s[ind] >= g[i] {
			ans++
			ind--
		}
	}
	return
}