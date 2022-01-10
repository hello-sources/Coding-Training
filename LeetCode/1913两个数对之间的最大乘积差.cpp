int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxProductDifference(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return (nums[0] * nums[1]) - (nums[numsSize - 1] * nums[numsSize - 2]);
}