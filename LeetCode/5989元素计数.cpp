int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b; 
}

int countElements(int* nums, int numsSize){
    int ans = 0;
    if (numsSize <= 2) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i <= numsSize - 2; i++) {
        if (nums[i] > nums[0] && nums[i] < nums[numsSize - 1]) ans++;
    }
    return ans;
}