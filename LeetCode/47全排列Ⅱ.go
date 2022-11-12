var ans [][]int
var path []int

func permuteUnique(nums []int) [][]int {
	ans = [][]int{}
	path = []int{}
	used := make([]bool, len(nums))
	sort.Ints(nums)
	backtracking(nums, used)
	return ans
}

func backtracking(nums []int, used []bool) {
	if len(path) == len(nums) {
		temp := make([]int, len(nums))
		copy(temp, path)
		ans = append(ans, temp)
	}
	for i := 0; i < len(nums); i++ {
		if used[i] == true || i > 0 && nums[i] == nums[i-1] && used[i-1] == false {
			continue
		}
		used[i] = true
		path = append(path, nums[i])
		backtracking(nums, used)
		path = path[:len(path)-1]
		used[i] = false
	}
}