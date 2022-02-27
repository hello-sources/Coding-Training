/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestSubarray(int* nums, int numsSize, int k, int* returnSize){
    int max = 0, ind = 0;
    for (int i = 0; i <= numsSize - k; i++) {
        if (max > nums[i]) continue;
        max = nums[i];
        ind = i;
    }
    int *res = (int *)malloc(sizeof(int) * k);
    *returnSize = 0;
    for (int i = ind; i < ind + k; i++) {
        res[(*returnSize)++] = nums[i];
    }
    return res;
}