/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *cal;

int calc(int n) {
    int cnt = 0;
    while (n) {
        cnt += (n % 2);
        n /= 2;
    }
    return cnt;
}

int cmp(void *a, void *b) {
    int x = *(int *)a, y = *(int *)b;
    return cal[x] == cal[y] ? x - y : cal[x] - cal[y];
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    cal = (int *)malloc(sizeof(int) * 10001);
    memset(cal, 0, sizeof(int) * 10001);
    for (int i = 0; i < arrSize; i++) {
        cal[arr[i]] = calc(arr[i]);
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    free(cal);
    *returnSize = arrSize;
    return arr;
}