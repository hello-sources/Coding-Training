/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int *nums = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        int temp = i, cnt = 0;
        while (temp) {
            if (temp % 2 == 1) cnt++;
            temp /= 2;
        }
        nums[i] = cnt;
    }
    *returnSize = n + 1;
    return nums;
}