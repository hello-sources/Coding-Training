int missingNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) return i;
    }
    return numsSize;
}