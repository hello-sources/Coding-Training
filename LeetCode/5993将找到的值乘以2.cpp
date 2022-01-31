int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findFinalValue(int* nums, int numsSize, int original){
    qsort(nums, numsSize, sizeof(int), cmp);
    int flag = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == original) original *= 2;
        
    }
    return original;
}