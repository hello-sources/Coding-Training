var ans [][]int
var path []int

func subsets(nums []int) [][]int {
	path = []int{}
	ans = [][]int{}
	// sort.Ints(nums)
	backtracking(nums, 0)
	return ans
}

func backtracking(nums []int, ind int) {
	temp := make([]int, len(path))
	copy(temp, path)
	ans = append(ans, temp)
	if ind >= len(nums) {
		return
	}
	for i := ind; i < len(nums); i++ {
		path = append(path, nums[i])
		backtracking(nums, i+1)
		path = path[:len(path)-1]
	}
}