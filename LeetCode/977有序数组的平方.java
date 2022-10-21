class Solution {
    public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] *= nums[i];
        }
        Arrays.sort(nums);
        return nums;
    }
}


/*
 * 双指针
 */
class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] ans = new int[nums.length];
        int k = ans.length - 1;
        for (int i = 0, j = nums.length - 1; i <= j; ) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans[k--] = nums[j] * nums[j];
                j--;
            } else {
                ans[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return ans;
    }
}