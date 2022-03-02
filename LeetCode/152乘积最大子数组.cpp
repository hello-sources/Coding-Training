int maxProduct(int* nums, int numsSize){
    int min[numsSize], max[numsSize];
    for (int i = 0; i < numsSize; i++) {
        min[i] = max[i] = nums[i];
    }
    for (int i = 1; i < numsSize; i++) {
        max[i] = fmax(max[i - 1] * nums[i], fmax(nums[i], min[i - 1] * nums[i]));
        min[i] = fmin(min[i - 1] * nums[i], fmin(nums[i], max[i - 1] * nums[i]));
    }
    int ans = max[0];
    for (int i = 1; i < numsSize; i++) ans = fmax(ans, max[i]);
    return ans;
}