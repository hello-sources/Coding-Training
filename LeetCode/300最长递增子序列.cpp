int lengthOfLIS(int* nums, int numsSize){
    if (numsSize < 1) return 0;
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = fmax(dp[i], dp[j] + 1);
        }
        ans = fmax(ans, dp[i]);
    }
    return ans;
}