int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int res[triangleSize][triangleSize];
    memset(res, 0, sizeof(res));
    res[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        res[i][0] = res[i - 1][0] + triangle[i][0];
        int j = 1;
        for (; j < i; j++) {
            res[i][j] = fmin(res[i - 1][j - 1], res[i - 1][j]) + triangle[i][j];
        }
        res[i][j] = res[i - 1][j - 1] + triangle[i][j];
    }
    int ans = res[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++) {
        ans = fmin(ans, res[triangleSize - 1][i]);
    }
    return ans;
}