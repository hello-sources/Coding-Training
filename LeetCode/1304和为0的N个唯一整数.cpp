/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (n + 5));
    if (n % 2) res[n / 2] = 0;
    for (int i = 0; i < n / 2; i++) {
        res[i] = -1000 - i;
        res[n - 1 - i] = 1000 + i;
    }
    *returnSize = n;
    return res;
}