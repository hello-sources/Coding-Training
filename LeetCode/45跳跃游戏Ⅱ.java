class Solution {
    public int jump(int[] nums) {
        int ans = 0, cur = 0, next = 0;
        if (nums.length == 1) return 0;
        for (int i = 0; i <= cur && cur < nums.length - 1; i++) {
            next = Math.max(i + nums[i], next);
            if (i == cur) {
                cur = next;
                ans++;
            }
        }
        return ans;
    }
}