int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findLHS(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int start = 0, length = 0;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] - nums[start] > 1) start++;
        if (nums[i] - nums[start] == 1) length = max(length, i - start + 1);
    }
    return length;
}