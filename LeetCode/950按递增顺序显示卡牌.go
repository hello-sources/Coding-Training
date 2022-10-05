func deckRevealedIncreasing(deck []int) []int {
	sort.Ints(deck)
	if len(deck) <= 2 {
		return deck
	}
	buf := []int{deck[len(deck)-1]}
	idx := len(deck) - 2
	for idx > 0 {
		buf = append(buf, deck[idx])
		t := buf[0]
		buf = buf[1:]
		buf = append(buf, t)
		idx--
	}
	buf = append(buf, deck[idx])
	s, e := 0, len(buf)-1
	for s < e {
		buf[s], buf[e] = buf[e], buf[s]
		s++
		e--
	}
	return buf
}

/*------------法二------------------*/
func deckRevealedIncreasing(deck []int) []int {
	n := len(deck)
	card := make([]int, n)
	sort.Ints(deck)

	i, j := 0, 0
	for i < n {
		card[j] = deck[i]
		i++
		// 移动2个位置

		if i >= n {
			break
		}

		t := 0
		for {
			j = (j + 1) % n
			if card[j] == 0 {
				t++
				if t == 2 {
					break
				}
			}
		}
	}
	return card
}