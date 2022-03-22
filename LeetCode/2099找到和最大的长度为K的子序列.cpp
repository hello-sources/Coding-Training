/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){
    int temp[numsSize];
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0, j = 0; i < numsSize; ++i) {
        if(temp[i] < nums[numsSize - k + j]) continue;
        else if(temp[i] == nums[numsSize - k + j]){
            res[(*returnSize)++] = temp[i];
            ++j;
        } else res[(*returnSize)++] = temp[i];
        if(*returnSize == k) break;
    }
    return res;
}