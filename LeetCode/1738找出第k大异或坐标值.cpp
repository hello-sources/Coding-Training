int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k){
    int m = matrixSize, n = matrixColSize[0], cnt = 0;
    int sum[m + 1][n + 1];
    memset(sum, 0, sizeof(sum));
    int *res = (int *)malloc(sizeof(int) * (m * n + 5));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] ^ sum[i][j - 1] ^ sum[i - 1][j - 1] ^ matrix[i - 1][j - 1];
            res[cnt++] = sum[i][j];
        }
    }
    qsort(res, cnt, sizeof(int), cmp);
    return res[cnt - k];
}