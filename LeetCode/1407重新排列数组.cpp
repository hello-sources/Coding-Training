/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        res[(*returnSize)++] = nums[i];
        res[(*returnSize)++] = nums[i + n];
    }
    return res;
}