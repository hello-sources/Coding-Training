int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minimumDifference(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int min = INT_MAX;
    for (int i = 0; i < numsSize && i + k <= numsSize; i++) {
        min = fmin(min, nums[i + k - 1] - nums[i]);
    }
    return min;
}