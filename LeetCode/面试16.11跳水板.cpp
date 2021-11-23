/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divingBoard(int shorter, int longer, int k, int* returnSize){
    if (k == 0) {
        *returnSize = 0;
        return 0;
    }
    if (shorter == longer) {
        int *p = (int *)malloc(sizeof(int));
        *p = shorter * k;
        *returnSize = 1;
        return p;
    }
    *returnSize = k + 1;
    int *ans = (int *)malloc(sizeof(int) * (k + 1));
    for (int i = 0; i <= k; i++) {
        ans[i] = shorter * (k - i) + longer * i;
    }
    return ans;
}