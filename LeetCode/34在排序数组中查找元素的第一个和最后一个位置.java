class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = -1, end = -1;
        boolean flag = true;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target && flag) {
                start = i;
                flag = false;
            }
            if (nums[i] == target && !flag) end = i;
        }
        return new int[]{start, end};
    }
}

/*-------------------------两个二分查找，左边界，有边界-----------------------------*/
func searchRange(nums []int, target int) []int {
    start := findLeftBound(nums, target)
    if start == len(nums) || nums[start] != target {
        return []int{-1, -1}
    }
    end := findRightBound(nums, target)
    return []int{start, end}
}

func findLeftBound(nums []int, target int) int {
    start, end := 0, len(nums) - 1
    for start <= end {
        mid := start + (end - start) >> 1
        if nums[mid] < target {
            start = mid + 1
        } else {
            end = mid - 1
        }
    }
    return start
}

func findRightBound(nums []int, target int) int {
    left, right := 0, len(nums) - 1
    for left <= right {
        mid := left + (right - left) >> 1
        if nums[mid] > target {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return right
}