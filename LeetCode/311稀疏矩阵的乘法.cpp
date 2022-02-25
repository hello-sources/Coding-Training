/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** multiply(int** mat1, int mat1Size, int* mat1ColSize, int** mat2, int mat2Size, int* mat2ColSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * mat1Size);
    *returnSize = mat1Size;
    *returnColumnSizes = (int *)malloc(mat1Size * sizeof(int));
    for (int i = 0; i < mat1Size; i++) {
        res[i] = (int *)calloc(mat2ColSize[0], sizeof(int));
        (*returnColumnSizes)[i] = mat2ColSize[0];
    }
    for (int i = 0; i < mat1Size; i++) {
        for (int j = 0; j < mat2ColSize[0]; j++) {
            for (int k = 0; k < mat2Size; k++) {
                res[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    return res;
}