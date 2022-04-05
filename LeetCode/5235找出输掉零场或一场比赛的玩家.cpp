/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes){
    int win[100005] = {0};
    int los[100005] = {0};
    for (int i = 0; i < matchesSize; i++) {
        win[matches[i][0]]++;
        los[matches[i][1]]++;
    }
    int **res = (int **)malloc(sizeof(int *) * 5);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 5);
    *returnSize = 2;
    for (int i = 0; i < 5; i++) {
        res[i] = (int *)malloc(sizeof(int) * matchesSize);
        memset(res[i], 0, sizeof(int) * matchesSize);
        (*returnColumnSizes)[i] = matchesSize;
    }
    int cnt = 0, cntl = 0;
    for (int i = 0; i < 100005; i++) {
        if (win[i] && los[i] == 0) res[0][cnt++] = i;
        else if (los[i] == 1) res[1][cntl++] = i;
    }
    (*returnColumnSizes)[0] = cnt;
    (*returnColumnSizes)[1] = cntl;
    return res;
}