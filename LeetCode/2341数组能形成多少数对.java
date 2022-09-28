class Solution {
    public int[] numberOfPairs(int[] nums) {
        int[] cnt = new int[105];
        int cnt_num = 0, cnt_double = 0;
        for (int i = 0; i < nums.length; i++) cnt[nums[i]]++;
        for (int i = 0; i < cnt.length; i++) {
            if (cnt[i] % 2 == 1) cnt_num++;
            cnt_double += cnt[i] / 2;
        }
        return new int[]{cnt_double, cnt_num};
    }
}