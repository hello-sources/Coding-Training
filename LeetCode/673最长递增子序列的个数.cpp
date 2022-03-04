int findNumberOfLIS(int* nums, int numsSize){
    int max = 0, ans = 1;
    int dp[numsSize], cnt[numsSize];
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[i] == dp[j] + 1) {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > max) max = dp[i], ans = cnt[i];
        else if (dp[i] == max) ans += cnt[i];
    }
    return ans;
}