func minMovesToSeat(seats []int, students []int) int {
	sort.Sort(sort.IntSlice(seats))
	sort.Sort(sort.IntSlice(students))
	var ans int = 0
	for i := 0; i < len(seats); i++ {
		ans += int(math.Abs(float64(seats[i]) - float64(students[i])))
	}
	return ans
}