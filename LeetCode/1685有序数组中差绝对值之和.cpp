/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (numsSize + 5));
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 5));
    memset(sum, 0, sizeof(sum));
    memset(res, 0, sizeof(res));
    for (int i = 0; i < numsSize; i++) {
        sum[i + 1] = nums[i] + sum[i];
    }
    for (int i = 0; i < numsSize; i++) {
        int left = i * nums[i] - sum[i];
        int right = sum[numsSize] - sum[i + 1] - (numsSize - 1 - i) * nums[i];
        res[i] = left + right;
    }
    free(sum);
    *returnSize = numsSize;
    return res;
}