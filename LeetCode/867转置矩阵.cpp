/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * matrixColSize[0]);
    *returnSize = matrixColSize[0];
    *returnColumnSizes = (int *)malloc(sizeof(int) * matrixColSize[0]);
    for (int i = 0; i < matrixColSize[0]; i++) {
        res[i] = (int *)malloc(sizeof(int) * matrixSize);
        (*returnColumnSizes)[i] = matrixSize;
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}