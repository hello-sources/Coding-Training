

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int cnt0 = 0, cnt1 = 0;
    int temp0 = 0, temp1 = 0;
    int *blow = (int *)malloc(sizeof(int) * (numsSize / 2 + 5));
    int *under = (int *)malloc(sizeof(int) * (numsSize / 2 + 5));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) under[cnt1++] = nums[i];
        else blow[cnt0++] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) nums[i] = under[temp1++];
        else nums[i] = blow[temp0++];
    }
    return nums;
}