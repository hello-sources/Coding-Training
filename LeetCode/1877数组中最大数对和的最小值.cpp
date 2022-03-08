int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int max = nums[0] + nums[numsSize - 1];
    for (int i = 1; i < numsSize / 2; i++) {
        max = fmax(max, nums[i] + nums[numsSize - i - 1]);
    }
    return max;
}