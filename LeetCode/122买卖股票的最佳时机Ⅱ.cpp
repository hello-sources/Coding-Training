/***************贪心做法****************/
int maxProfit(int* prices, int pricesSize){
    int ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        ans += fmax(0, prices[i] - prices[i - 1]);
    }
    return ans;
}

/***************动态规划*************/
int maxProfit(int* prices, int pricesSize){
    int dp[pricesSize][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}