int calc(int *nums, int start, int end) {
    int first = nums[start], second = fmax(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        int third = second;
        second = fmax(second, first + nums[i]);
        first = third;
    }
    return second;
}

int rob(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return fmax(nums[0], nums[1]);
    return fmax(calc(nums, 1, numsSize - 1), calc(nums, 0, numsSize - 2));
}