int missingNumber(int* nums, int numsSize){
    int num[numsSize + 1];
    memset(num, 0, sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]] = 1;
    }
    for (int i = 0; i <= numsSize; i++) {
        if (num[i] == 0) return i;
    }
    return -1;
}