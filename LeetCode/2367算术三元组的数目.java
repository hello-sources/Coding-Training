/**
 * 未优化，暴力硬解
 */
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int ans = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff) ans++;
                }
            }
        }
        return ans;
    }
}

/**
 * 二分查找优化
 */
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int count = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            int nextNumIdx = binarySearch(nums, i + 1, nums.length - 1, nums[i] + diff);
            if (nextNumIdx != -1) {
                int nextNextNumIdx = binarySearch(nums, nextNumIdx + 1, nums.length - 1, nums[nextNumIdx] + diff);
                if (nextNextNumIdx != -1) {
                    count += 1;
                }
            }
        }
        return count;
    }
    
    private int binarySearch(int[] nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}