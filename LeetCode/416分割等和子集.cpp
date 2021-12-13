/**
 * 动态规划中类似于0-1背包问题
 * 创建二维数组dp，包含n行target+1列，
 * 其中dp[i][j]表示从数组的[0,i]下标范围内选取若干个正整数（可以是0个），
 * 是否存在一种选取方案使得被选取的正整数的和等于 j。初始时dp中的全部元素都是false。
 * 考虑数组边界，如果不选取任何元素，被选取的正整数为0，当i==0时，只有一个元素被选取dp[0][nums[0]]=true
 * 如果j≥nums[i]，则对于当前的数字nums[i]，可以选取也可以不选取，两种情况只要有一个为 true，就有dp[i][j]=true。
 * 如果不选取nums[i]，则dp[i][j]=dp[i−1][j]；
 * 如果选取nums[i]，则dp[i][j]=dp[i−1][j−nums[i]]。
 * 如果 j<nums[i]，则在选取的数字的和等于 j 的情况下无法选取当前的数字nums[i]，因此有dp[i][j]=dp[i−1][j]。
 * */

bool canPartition(int* nums, int numsSize){
    int ans = 0, max = 0;
    if (numsSize < 2) return false;
    for (int i = 0; i < numsSize; i++) {
        ans += nums[i];
        max = fmax(max, nums[i]);
    }
    if (ans % 2 == 1) return false;
    int target = ans >> 1;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] |= dp[j - nums[i]];
        }
    }
    return dp[target];
}