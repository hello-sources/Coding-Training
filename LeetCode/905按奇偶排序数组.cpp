/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) ans[(*returnSize)++] = nums[i], nums[i] = -1;
    }
    for (int i = 0; i< numsSize; i++) {
        if (nums[i] != -1) ans[(*returnSize)++] = nums[i];
    }
    return ans;
}

//双指针
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int head = 0, tail = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & 1) {
            ans[tail--] = nums[i];
        } else {
            ans[head++] = nums[i];
        }
    }
    return ans;
}