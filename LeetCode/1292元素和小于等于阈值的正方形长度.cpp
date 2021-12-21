int sum[305][305];
int m, n;
int calc (int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold){
    memset(sum, 0, sizeof(sum));
    m = matSize, n = matColSize[0];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    int left = 1, right = fmin(m, n), ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        bool find = false;
        for (int i = 1; i <= m - mid + 1; i++) {
            for (int j = 1; j <= n - mid + 1; j++) {
                if (calc(i, j, i + mid - 1, j + mid - 1) <= threshold) find = true;
            }
        }
        if (find) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}