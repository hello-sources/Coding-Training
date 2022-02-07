/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int r0, c0;

int cmp(const void *_a, const void *_b) {
    int *a = *(int **)_a, *b = *(int **)_b;
    return fabs(a[0] - r0) + fabs(a[1] - c0) - fabs(b[0] - r0) - fabs(b[1] - c0);
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes){
    r0 = rCenter, c0 = cCenter;
    int **res = (int **)malloc(sizeof(int *) * rows * cols);
    *returnColumnSizes = (int *)malloc(sizeof(int) * rows * cols);
    for (int i = 0; i < cols * rows; i++) {
        (*returnColumnSizes)[i] = 2;
        res[i] = (int *)malloc(sizeof(int) * 2);
    }
    *returnSize = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[(*returnSize)][0] = i;
            res[(*returnSize)++][1] = j;
        }
    }
    qsort(res, rows * cols, sizeof(int *), cmp);
    return res;
}