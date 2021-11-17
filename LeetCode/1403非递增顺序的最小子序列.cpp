/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void*a,const void*b) {
    return *(int*)b-*(int*)a;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize){
    int cnt = 0, cnt1 = 0, i;
    for (int i = 0; i < numsSize; i++) cnt1 += nums[i];
    qsort(nums, numsSize, sizeof(int),cmp);
    for (i = 0; i < numsSize; i++) {
        if (cnt > cnt1) break;
        cnt += nums[i];
        cnt1 -= nums[i];
    }
    *returnSize = i;
    return nums;
}