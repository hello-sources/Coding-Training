/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int start = -1, end = -1, flag = 1;
    int *ans = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target && flag) start = i, flag = 0;
        if (nums[i] == target && !flag) end = i;
    }
    ans[0] = start;
    ans[1] = end;
    *returnSize = 2;
    return ans;
}