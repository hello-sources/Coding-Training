/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int rol[matrixSize], col[matrixColSize[0]];
    memset(col, 0, sizeof(int) * matrixColSize[0]);
    for (int i = 0; i < matrixSize; i++) rol[i] = INT_MAX;
    int *ans = (int *)malloc(sizeof(int) * (matrixSize * matrixColSize[0] + 5));
    *returnSize = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] < rol[i]) rol[i] = matrix[i][j];
            if (matrix[i][j] > col[j]) col[j] = matrix[i][j];
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == rol[i] && matrix[i][j] == col[j]) ans[(*returnSize)++] = matrix[i][j];
        }
    }
    return ans;
}