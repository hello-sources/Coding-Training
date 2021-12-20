int pivotIndex(int* nums, int numsSize){
    int ans = 0, total = 0;
    for (int i = 0; i < numsSize; i++) ans += nums[i];
    for (int i = 0; i < numsSize; i++) {
        if (2 * total + nums[i] == ans) return i;
        total += nums[i];
    }
    return -1;
}