long long subArrayRanges(int* nums, int numsSize){
    int min, max;
    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        max = min = nums[i];
        for (int j = i; j < numsSize; j++) {
            min = fmin(nums[j], min);
            max = fmax(nums[j], max);
            ans += max - min;
        }
    }
    return ans;
}