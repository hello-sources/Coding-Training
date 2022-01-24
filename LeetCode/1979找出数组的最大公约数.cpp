int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findGCD(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int max = nums[numsSize - 1], min = nums[0];
    for (int i = max; i > 0; i--) {
        if (max % i == 0 && min % i == 0) return i;
    }
    return -1;
}