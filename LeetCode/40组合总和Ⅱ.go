var ans [][]int
var used []bool
var nums []int

func combinationSum2(candidates []int, target int) [][]int {
	ans = [][]int{}
	used = make([]bool, len(candidates))
	nums = []int{}
	sort.Ints(candidates)
	backtracking(0, 0, candidates, target)
	return ans
}

func backtracking(ind int, sum int, candidates []int, target int) {
	if sum == target {
		temp := make([]int, len(nums))
		copy(temp, nums)
		ans = append(ans, temp)
		return
	}
	for i := ind; i < len(candidates) && sum+candidates[i] <= target; i++ {
		if i > 0 && candidates[i] == candidates[i-1] && !used[i-1] {
			continue
		}
		used[i] = true
		sum += candidates[i]
		nums = append(nums, candidates[i])
		backtracking(i+1, sum, candidates, target)
		nums = nums[:len(nums)-1]
		sum -= candidates[i]
		used[i] = false
	}
}