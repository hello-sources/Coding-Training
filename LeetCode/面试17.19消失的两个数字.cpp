/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingTwo(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);
    *returnSize = 0;
    int num[300005] = {0};
    for (int i = 0; i < numsSize; i++) num[nums[i]]++;
    for (int i = 1; i < numsSize + 3; i++) {
        if (num[i] == 0) res[(*returnSize)++] = i;
    }
    return res;
}