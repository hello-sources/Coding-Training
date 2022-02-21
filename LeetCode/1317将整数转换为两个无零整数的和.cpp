/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool contain(int x) {
    if (x == 0) return false;
    while (x) {
        if (x % 10 == 0) return false;
        x /= 10;
    }
    return true;
}

int* getNoZeroIntegers(int n, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 0;
    memset(res, 0, sizeof(int) * 2);
    for (int i = 1; i < n; i++) {
        int left = n - i;
        if (contain(left) && contain(i)) {
            res[(*returnSize)++] = i;
            res[(*returnSize)++] = left;
            return res;
        }
    }
    return NULL;
}