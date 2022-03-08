int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    int dp[matrixSize][matrixSize];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < matrixSize; i++) dp[0][i] = matrix[0][i];
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (j == 0) dp[i][j] = fmin(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
            else if (j == matrixSize - 1) {
                dp[i][j] = fmin(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
            } else {
                dp[i][j] = fmin(dp[i - 1][j - 1], fmin(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j];
            }
        }
    }
    int min = dp[matrixSize - 1][0];
    for (int i = 1; i < matrixSize; i++) min = fmin(min, dp[matrixSize - 1][i]);
    return min;
}