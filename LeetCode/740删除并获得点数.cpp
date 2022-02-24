int calc(int *nums, int numsSize) {
    int first = nums[0], second = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        int third = second;
        second = fmax(first + nums[i], second);
        first = third;
    }
    return second;
}

int deleteAndEarn(int* nums, int numsSize){
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        max = fmax(max, nums[i]);
    }
    int num[max + 1];
    memset(num, 0, sizeof(num));
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]] += nums[i];
    }
    return calc(num, max + 1);
}