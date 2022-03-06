/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) res[(*returnSize)++] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == pivot) res[(*returnSize)++] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > pivot) res[(*returnSize)++] = nums[i];
    }
    return res;
}