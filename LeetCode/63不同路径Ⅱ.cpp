int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize, n = obstacleGridColSize[0];
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    if (obstacleGrid[0][0] == 1) return 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

/**************一维DP（滚动数组）****************/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize, n = obstacleGridColSize[0];
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
                continue;
            }
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[n - 1];
}