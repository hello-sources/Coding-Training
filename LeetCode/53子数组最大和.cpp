int maxSubArray(int* nums, int numsSize){
    int temp = 0, max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        temp = fmax(temp + nums[i], nums[i]);
        max = fmax(max, temp);
    }
    return max;
}