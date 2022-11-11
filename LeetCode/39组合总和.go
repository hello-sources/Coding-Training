var ans [][]int
var num []int

func combinationSum(candidates []int, target int) [][]int {
	ans = [][]int{}
	num = []int{}
	backtracking(0, 0, candidates, target)
	return ans
}

func backtracking(sum int, ind int, candidates []int, target int) {
	if sum > target {
		return
	}
	if sum == target {
		temp := make([]int, len(num))
		copy(temp, num)
		ans = append(ans, temp)
		return
	}
	for i := ind; i < len(candidates); i++ {
		sum += candidates[i]
		num = append(num, candidates[i])
		backtracking(sum, i, candidates, target)
		num = num[:len(num)-1]
		sum -= candidates[i]
	}
	return
}