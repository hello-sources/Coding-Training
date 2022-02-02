int minCostClimbingStairs(int* cost, int costSize){
    int dp[costSize + 5], ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= costSize; i++) {
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[costSize];
}