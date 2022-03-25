double findMaxAverage(int* nums, int numsSize, int k){
    double average = 0;
    if (numsSize < k) return 0;
    double sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    average = sum / k;
    for (int i = k; i < numsSize; i++) {
        sum -= nums[i - k];
        sum += nums[i];
        average = fmax(average, sum / k);
    }
    return average;
}