int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int arrayPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < numsSize; i += 2) {
        ans += fmin(nums[i], nums[i + 1]);
    }
    return ans;
}