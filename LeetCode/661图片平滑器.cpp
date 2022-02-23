/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int calc(int **img, int x, int y, int imgSize, int imgColSize) {
    int sum = 0, cnt = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < imgSize && j >= 0 && j < imgColSize) {
                sum += img[i][j];
                cnt++;
            }
        }
    }
    return sum / cnt;
}

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * imgSize);
    *returnSize = imgSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * imgSize);
    for (int i = 0; i < imgSize; i++) {
        res[i] = (int *)malloc(sizeof(int) * imgColSize[0]);
        (*returnColumnSizes)[i] = imgColSize[0];
    }
    for (int i = 0; i < imgSize; i++) {
        for (int j = 0; j < imgColSize[0]; j++) {
            res[i][j] = calc(img, i, j, imgSize, imgColSize[0]);
        }
    }
    return res;
}