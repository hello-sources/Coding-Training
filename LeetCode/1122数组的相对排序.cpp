/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    *returnSize = 0;
    int cnt1 = 0, cal = 0;
    int *ans = (int *)malloc(sizeof(int) * arr1Size);
    int *cnt = (int *)malloc(sizeof(int) * arr1Size);
    int *ret = (int *)malloc(sizeof(int) * arr1Size);
    for (int i = 0; i < arr2Size; i++) {
        for (int j = 0; j < arr1Size; j++) {
            if (arr1[j] == arr2[i]) ans[(*returnSize)++] = arr2[i], cnt[j] = 1;
        }
    }
    for (int i = 0; i < arr1Size; i++) {
        if (cnt[i] == 1) {
            cnt1++;
            continue;
        }
        ans[(*returnSize)++] = arr1[i];
    }
    for (int i = (*returnSize) - 1; i >= cnt1; i--) {
        ret[cal++] = ans[i];
    }
    qsort(ret, cal, sizeof(int), cmp);
    int j = 0;
    for (int i = cnt1; i < (*returnSize); i++) {
        ans[i] = ret[j++];
    }
    return ans;
}