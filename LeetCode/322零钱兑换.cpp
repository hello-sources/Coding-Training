int coinChange(int* coins, int coinsSize, int amount){
    int dp[amount + 1];
    for (int i = 0; i < amount + 1; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = fmin(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}