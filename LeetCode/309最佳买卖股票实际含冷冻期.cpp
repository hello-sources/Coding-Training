int maxProfit(int* prices, int pricesSize){
    int dp[pricesSize][3];
    dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0;
    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        dp[i][1] = dp[i - 1][0] + prices[i];
        dp[i][2] = fmax(dp[i - 1][1], dp[i - 1][2]);
    }
    return fmax(dp[pricesSize - 1][1], dp[pricesSize - 1][2]);
}