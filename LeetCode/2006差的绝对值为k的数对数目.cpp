int countKDifference(int* nums, int numsSize, int k){
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (fabs(nums[i] - nums[j]) == k) cnt++;
        }
    }
    return cnt;
}