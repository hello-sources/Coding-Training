/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
    int cnt = 0;
    int *res = (int *)malloc(sizeof(int) * (numsSize + 5));
    for (int i = 0; i < numsSize; i++) {
        res[cnt++] = nums[nums[i]];
    }
    *returnSize = cnt;
    return res;
}