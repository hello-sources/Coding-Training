int numWays(int n, int** relation, int relationSize, int* relationColSize, int k){
    int dp[k + 1][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0;  i < k; i++) {
        for (int j = 0; j < relationSize; j++) {
            int src = relation[j][0], dis = relation[j][1];
            dp[i + 1][dis] += dp[i][src];
        }
    }
    return dp[k][n - 1];
}