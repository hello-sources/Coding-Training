class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int start = 0, sum = 0, ans = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            while (sum >= target) {
                int length = i - start + 1;
                ans = Math.min(ans, length);
                sum -= nums[start++];
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}