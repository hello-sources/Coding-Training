int combinationSum4(int* nums, int numsSize, int target){
    int dp[target + 5];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] <= i && (dp[i - nums[j]] < INT_MAX - dp[i])) dp[i] += dp[i - nums[j]];
        }
    }
    return dp[target];
}

/***********************二维DP***********************/
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int combinationSum4(int* nums, int numsSize, int target){
    if (target == 0) return 1;
    if (nums == NULL) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int dp[target + 1][numsSize + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= numsSize; i++) dp[0][i] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 1; j <= numsSize; j++) {
            if (i >= nums[j - 1]) {
                for (int k = 0; k < j; k++) {
                    if (dp[i - nums[k]][j] < INT_MAX - dp[i][j]) {
                        dp[i][j] += dp[i - nums[k]][j];
                    }
                }
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[target][numsSize];
}