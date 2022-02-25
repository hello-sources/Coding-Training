int sumOfDigits(int* nums, int numsSize){
    int min = nums[0], ans = 0;
    for (int i = 0; i < numsSize; i++) min = fmin(min, nums[i]);
    while (min) {
        ans += (min % 10);
        min /= 10;
    }
    return ans % 2 == 1 ? 0 : 1;
}