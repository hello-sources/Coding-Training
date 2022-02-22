int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int largestPerimeter(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = numsSize - 1; i >= 2; i--) {
        if (nums[i - 2] + nums[i - 1] > nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }
    return 0;
}