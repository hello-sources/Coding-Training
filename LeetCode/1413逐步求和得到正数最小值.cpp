int minStartValue(int* nums, int numsSize){
    int sum = 0, temp = nums[0];
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        temp = fmin(temp, sum);
    }
    if (temp >= 1) return 1;
    return 1 - temp;
}