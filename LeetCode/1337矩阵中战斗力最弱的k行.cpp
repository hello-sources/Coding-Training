/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int calc(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i];
    }
    return count;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * matSize);
    *returnSize = k;
    memset(ans, 0, sizeof(int));
    for (int i = 0; i < matSize; i++) {
        int cnt = 0;
        for (int j = 0; j < matColSize[0]; j++) {
            cnt += mat[i][j];
        }
        ans[i] = cnt * matSize + i;
        //ans[i] = calc(mat[i], matColSize[i]) * matSize + i;
    }
    qsort(ans, matSize, sizeof(int), cmp);
    for (int i = 0; i < matSize; i++) {
        ans[i] %= matSize;
    }
    return ans;
}