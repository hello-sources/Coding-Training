/**************************贪心做法******************************/
int maxProfit(int* prices, int pricesSize, int fee){
    int ans = 0, buy = prices[0] + fee;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] + fee < buy) buy = prices[i] + fee;
        else if (prices[i] > buy) {
            ans += prices[i] - buy;
            buy = prices[i];
        }
    }
    return ans;
}

/***************************动态规划******************************/
int maxProfit(int* prices, int pricesSize, int fee){
    int dp[pricesSize][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}