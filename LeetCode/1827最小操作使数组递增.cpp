int minOperations(int* nums, int numsSize){
    int ans = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) continue;
        else {
            int left = nums[i - 1] - nums[i];
            ans += left + 1;
            nums[i] = nums[i - 1] + 1;
        }
    }
    return ans;
}