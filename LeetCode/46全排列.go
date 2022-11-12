var ans [][]int
var path []int
var used []bool

func permute(nums []int) [][]int {
	ans = [][]int{}
	path = []int{}
	used = make([]bool, len(nums))
	backtracking(nums)
	return ans
}

func backtracking(nums []int) {
	if len(path) == len(nums) {
		temp := make([]int, len(nums))
		copy(temp, path)
		ans = append(ans, temp)
	}
	for i := 0; i < len(nums); i++ {
		if used[i] == true {
			continue
		}
		used[i] = true
		path = append(path, nums[i])
		backtracking(nums)
		path = path[:len(path)-1]
		used[i] = false
	}
}