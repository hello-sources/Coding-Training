/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr, arrSize, sizeof(int), cmp);
    int min = INT_MAX, cnt = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] < min) {
            min = arr[i] - arr[i - 1];
            cnt = 1;
        } else if (min == arr[i] - arr[i - 1]) {
            cnt++;
        }
    }
    int **res = (int **)malloc(sizeof(int *) * cnt);
    *returnColumnSizes = (int *)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == min) {
            res[(*returnSize)][0] = arr[i - 1];
            res[(*returnSize)++][1] = arr[i];
        }
    }
    return res;
}