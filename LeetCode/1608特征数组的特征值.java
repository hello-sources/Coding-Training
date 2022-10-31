class Solution {
    public int specialArray(int[] nums) {
        // Arrays.sort(nums, Collections.reverseOrder();
        nums = Arrays.stream(nums).boxed().sorted((a, b) -> b - a).mapToInt(p -> p).toArray();
        int left = 1, right = nums.length;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid - 1] >= mid) {
                if (nums.length == mid || nums[mid] < mid) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else {    
                right = mid - 1;
            }
        }
        return -1;
    }
}