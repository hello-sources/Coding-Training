int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int repeatedNTimes(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    if (numsSize == 2) return nums[0];
    if (nums[numsSize / 2] == nums[numsSize / 2 + 1]) return nums[numsSize / 2];
    else return nums[numsSize / 2 - 1];
}