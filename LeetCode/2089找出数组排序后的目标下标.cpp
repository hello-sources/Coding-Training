/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) res[(*returnSize)++] = i;
    }
    return res;
}