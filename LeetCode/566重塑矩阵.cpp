/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int m = matSize, n = matColSize[0];
    int *temp = (int *)malloc(sizeof(int) * (m * n + 5));
    int cnt = 0, index = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[0]; j++) {
            temp[cnt++] = mat[i][j];
        }
    }
    if (m * n != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    *returnSize = r;
    *returnColumnSizes = (int *)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }
    int **res = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        res[i] = (int *)malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            res[i][j] = temp[index++];
        }
    }  
    return res;
}

/***********************小优化***************************/
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int m = matSize, n = matColSize[0];
    int cnt = 0, index = 0;
    if (m * n != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    *returnSize = r;
    *returnColumnSizes = (int *)malloc(sizeof(int) * r);
    int **res = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        res[i] = (int *)malloc(sizeof(int) * c);
    }
    for (int i = 0; i < m * n; i++) {
        res[i / c][i % c] = mat[i / n][i % n];
    }
    return res;
}