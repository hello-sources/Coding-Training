int uniquePaths(int m, int n){
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

/*************************一维DP（滚动数组）*************************/
int uniquePaths(int m, int n){
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= 1) dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}