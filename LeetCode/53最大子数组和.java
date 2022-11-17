class Solution {
    public int maxSubArray(int[] nums) {
        int cnt = 0, ans = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            cnt += nums[i];
            if (cnt > ans) ans = cnt;
            if (cnt <= 0) cnt = 0;
        }
        return ans;
    }
}