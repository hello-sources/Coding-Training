/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int len = (numsSize == 0 ? 0 : numsSize - k + 1);
    int *res = (int *)malloc(sizeof(int) * len);
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    int head = 0, tail = 0;
    for (int i = 0; i < numsSize; i++) {
        while (tail - head && nums[i] > nums[ret[tail - 1]]) tail--;
        ret[tail++] = i;
        if (i - ret[head] + 1 > k) head++;
        if (i + 1 >= k) res[(*returnSize)++] = nums[ret[head]];
    }
    free(ret);
    return res;
}