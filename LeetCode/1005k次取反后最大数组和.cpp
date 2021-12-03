int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int largestSumAfterKNegations(int* nums, int numsSize, int k){
    int ans = 0, cnt0 = 0;
    while (cnt0 < k) {
        qsort(nums, numsSize, sizeof(int), cmp);
        nums[0] = - nums[0];
        cnt0++;
    }
    for (int i = 0; i < numsSize; i++) {
        ans += nums[i];
    }
    return ans;
}