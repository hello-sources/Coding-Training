/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize){
    int num[10] = {0};
    for (int i = 0; i < digitsSize; i++) {
        num[digits[i]]++;
    }
    int *res = (int *)malloc(sizeof(int) * 999);
    *returnSize = 0;
    for (int i = 100; i < 999; i += 2) {
        int cnt[10] = {0};
        int temp = i;
        while (temp) {
            int t = temp % 10;
            if (++cnt[t] > num[t]) break;
            temp /= 10;
        }
        if (temp == 0) res[(*returnSize)++] = i;
    }
    return res;
}