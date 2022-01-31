

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxScoreIndices(int* nums, int numsSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 100005);
    int temp[100005] = {0};
    int max = 0, cntl0 = 0, cnt1 = 0, cnt0 = 0;
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) cnt1++;
        else cnt0++;
    }
    for (int i = 0; i <= numsSize; i++) {
        if (i == 0) temp[i] = cnt1;
        else if (i == numsSize) temp[i] = cnt0;
        else {
            if (nums[i - 1] == 0) cntl0++;
            temp[i] = cntl0 + (cnt1 - (i - cntl0));
        }
        max = fmax(max, temp[i]);
    }
    for (int i = 0; i <= numsSize; i++) {
        if (temp[i] == max) ans[(*returnSize)++] = i;
    }
    return ans;
}