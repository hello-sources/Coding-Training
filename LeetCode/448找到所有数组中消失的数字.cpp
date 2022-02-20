/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_N 100005
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int num[MAX_N] = {0};
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]]++;
    }
    for (int i = 1; i <= numsSize; i++) {
        if (num[i] == 0) res[(*returnSize)++] = i;
    }
    return res;
}