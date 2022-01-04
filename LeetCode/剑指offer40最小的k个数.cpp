/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * arrSize);
    qsort(arr, arrSize, sizeof(int), cmp);
    int cnt = 0;
    for (int i = 0; i < k; i++) res[cnt++] = arr[i];
    *returnSize = cnt;
    return res;
}