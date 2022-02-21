int findShortestSubArray(int* nums, int numsSize){
    int l = 0, r = 0, max = 0;
    int res = numsSize;
    int *num = (int *)malloc(sizeof(int) * 50001);
    memset(num, 0, sizeof(int) * 50001);
    for (int i = 0; i < numsSize; i++) {
        max = fmax(max, ++num[nums[i]]);
    }
    memset(num, 0, sizeof(int) * 50001);
    for (r = 0; r < numsSize; r++) {
        num[nums[r]]++;
        while (num[nums[r]] == max) {
            res = fmin(res, r - l + 1);
            num[nums[l++]]--;
        }
    }
    free(num);
    return res;
}