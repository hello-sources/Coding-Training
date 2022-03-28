/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * n);
    memset(res, 0, sizeof(int) * n);
    int temp_sum = 0, sum = 0, left = 0;
    *returnSize = 0;
    for (int i = 0; i < rollsSize; i++) temp_sum += rolls[i];
    sum = mean * (n + rollsSize);
    left = sum - temp_sum;
    if (left > n * 6 || left < n) {
        return NULL;
    }
    while (left > 0) {
        for (int i = 0; i < n && left; i++) {
            res[i]++;
            left--;
        }
    }
    *returnSize = n;
    return res;
}