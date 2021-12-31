/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes){
    if (m * n != originalSize) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    int **res = (int **)malloc(sizeof(int *) * m);
     for (int i = 0; i < m; ++i) {
        res[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    for (int i = 0; i < originalSize; i++) {
        res[i / n][i % n] = original[i];
    }
    return res;
}