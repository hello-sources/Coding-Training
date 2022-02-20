

long long coutPairs(int* nums, int numsSize, int k){
    long long ans = 0;
    long long num = k;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            long long temp1 = nums[i];
            long long temp2 = nums[j];
            temp1 %= num;
            temp2 %= num;
            if ((temp1 * temp2) % num == 0) ans++;
        }
    }
    return ans;
}