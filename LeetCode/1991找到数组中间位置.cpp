int findMiddleIndex(int* nums, int numsSize){
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 5));
    sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        int l = (i == 0 ? 0 : sum[i - 1]);
        int r = sum[numsSize - 1] - sum[i];
        if (l == r) return i;
    }
    return -1;
}

/******************差不多*********************/
int findMiddleIndex(int* nums, int numsSize){
    int sum = 0, total = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    for (int i = 0; i < numsSize; i++) {
        if (2 * total + nums[i] == sum) return i;
        total += nums[i];
    }
    return -1;
}