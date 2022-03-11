/************************暴力最大正方形**************************/
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int maxSide = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) return 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                maxSide = fmax(maxSide, 1);
                int currentMaxSide = fmin(matrixSize - i, matrixColSize[0] - j);
                for (int k = 1; k < currentMaxSide; k++) {
                    bool flag = true;
                    if (matrix[i + k][j + k] == '0') break;
                    for (int m = 0; m < k; m++) {
                        if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        maxSide = fmax(maxSide, k + 1);
                    } else break;
                }
            }
        }
    }
    return maxSide * maxSide;
}

/*********************动态规划策略*******************/
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int maxSide = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) return 0;
    int dp[matrixSize][matrixColSize[0]];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
            maxSide = fmax(maxSide, dp[i][j]);
        }
    }
    return maxSide * maxSide;
}