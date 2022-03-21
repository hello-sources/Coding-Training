int maxCoins(int* nums, int numsSize){
    int dp[numsSize + 2][numsSize + 2];
    memset(dp, 0, sizeof(dp));
    int val[numsSize + 2];
    val[0] = val[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        val[i] = nums[i - 1];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i + 2; j <= numsSize + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                int sum = val[i] * val[k] * val[j];
                sum += dp[i][k] + dp[k][j];
                dp[i][j] = fmax(dp[i][j], sum);
            }
        }
    }
    return dp[0][numsSize + 1];
}