int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int specialArray(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (numsSize - i <= nums[i]) {
            if (i == 0 || (i != 0 && numsSize - i > nums[i - 1])) return numsSize - i;
        }
    }
    return -1;
}