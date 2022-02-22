int maxSubArray(int* nums, int numsSize){
    int pre = 0, max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        pre = fmax(pre + nums[i], nums[i]);
        max = fmax(max, pre);
    }
    return max;
}