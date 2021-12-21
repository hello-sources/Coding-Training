/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int calc(int **num, int l, int r, int row, int col, int k) {
    int sum = 0;
    for (int i = l - k; i <= l + k; i++) {
        if (!(i >= 0 && i < row)) continue;
        for (int j = r - k; j <= r + k; j++) {
            if (!(j >= 0 && j < col)) continue;
            sum += num[i][j];
        }
    }
    return sum;
}

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes){
    int **ans = (int **)malloc(sizeof(int *) * matSize);
    *returnSize = matSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * matSize);
    for (int i = 0; i < matSize; i++) {
        ans[i] = (int *)malloc(sizeof(int) * matColSize[0]);
        (*returnColumnSizes)[i] = matColSize[0];
        for (int j = 0; j < matColSize[0]; j++) {
            ans[i][j] = calc(mat, i, j, matSize, matColSize[0], k);
        }
    }
    return ans;
}

/******************二维数组前缀和******************/
int sum[101][101];
int r, c;
int calc(int x1, int x2, int y1, int y2) {
    x1 = x1 < 1 ? 1 : x1;
    x2 = x2 > r ? r : x2;
    y1 = y1 < 1 ? 1 : y1;
    y2 = y2 > c ? c : y2;
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes){
    memset(sum, 0, sizeof(sum));
    r = matSize;
    c = matColSize[0];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    int **res = (int **)malloc(sizeof(int *) * matSize);
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    for (int i = 0; i < matSize; i++) {
        res[i] = (int *)malloc(sizeof(int) * matColSize[0]);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            res[i - 1][j - 1] = calc(i - k, i + k, j - k, j + k);
        }
    }
    return res;
}