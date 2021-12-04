int findRepeatNumber(int* nums, int numsSize){
    int num[100000] = {0};
    int i = 0;
    for (; i < numsSize; i++) {
        num[nums[i]]++;
        if (num[nums[i]] > 1) return nums[i];
    } 
    return nums[i];
}