int numberOfArithmeticSlices(int* nums, int numsSize){
    if (numsSize == 1) return 0;
    int ans = 0, t = 0, d = nums[1] - nums[0];
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] == d) {
            t++;
        } else {
            d = nums[i] - nums[i - 1];
            t = 0;
        }
        ans += t;
    }
    return ans;
}
/*********************暴力******************/
bool judge(int *nums, int l, int r) {
    if (r - l < 2) return false;
    for (int i = l; i < r - 1; i++) {
        if (nums[i + 1] * 2 != nums[i] + nums[i + 2]) return false;
    }
    return true;
}

int numberOfArithmeticSlices(int* nums, int numsSize){
    if (numsSize < 3) return 0;
    int ans = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (judge(nums, i, j)) ans++;
        }
    }
    return ans;
} 

/********************动态规划********************/
int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    int dp[numsSize], ans = 0;
    memset(dp, 0, sizeof(int) * numsSize);
    dp[0] = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] * 2 == nums[i - 1] + nums[i + 1]) dp[i] = dp[i - 1] + 1;
    }
    for (int i = 0; i < numsSize; i++) ans += dp[i];
    return ans;
}