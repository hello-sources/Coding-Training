bool isMonotonic(int* nums, int numsSize){
    int flag1 = 1, flag2 = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) flag1 = 0;
        if (nums[i - 1] < nums[i]) flag2 = 0;
    }
    return flag2 || flag1;
}