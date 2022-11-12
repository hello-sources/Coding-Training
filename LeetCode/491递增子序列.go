var ans [][]int
var path []int

func findSubsequences(nums []int) [][]int {
	ans = [][]int{}
	path = []int{}
	backtracking(nums, 0)
	return ans
}

func backtracking(nums []int, ind int) {
	if len(path) > 1 {
		temp := make([]int, len(path))
		copy(temp, path)
		ans = append(ans, temp)
	}
	cnt := make([]int, 205)
	for i := ind; i < len(nums); i++ {
		if len(path) > 0 && nums[i] < path[len(path)-1] || cnt[nums[i]+100] == 1 {
			continue
		}
		cnt[nums[i]+100] = 1
		path = append(path, nums[i])
		backtracking(nums, i+1)
		path = path[:len(path)-1]
	}
}