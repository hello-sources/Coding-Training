int maxAscendingSum(int* nums, int numsSize){
    int max = INT_MIN, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = (i != 0 && nums[i] > nums[i - 1]) ? sum + nums[i] : nums[i];
        max = fmax(max, sum);
    }
    return max;
}