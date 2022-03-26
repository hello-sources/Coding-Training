/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);
    int num[100005] = {0};
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]]++;
    }
    for (int i = 1; i < 100005; i++) {
        if (num[i] == 2) res[(*returnSize)++] =  i;
    }
    return res;
}

/**********************大佬做法*******************/
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        nums[(nums[i] - 1) % numsSize] += numsSize;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 2 * numsSize) {
            nums[(*returnSize)++] = i + 1;
        }
    }
    return nums;
}