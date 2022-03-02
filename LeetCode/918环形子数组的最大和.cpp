int maxSubarraySumCircular(int* nums, int numsSize){
    int ans = 0, max = nums[0], curMax = 0, min = nums[0], curMin = 0;
    for (int i = 0; i < numsSize; i++) {
        curMax = fmax(curMax + nums[i], nums[i]);
        max = fmax(max, curMax);
        curMin = fmin(curMin + nums[i], nums[i]);
        min = fmin(min, curMin);
        ans += nums[i];
    }
    return max > 0 ? fmax(max, ans - min) : max;
}