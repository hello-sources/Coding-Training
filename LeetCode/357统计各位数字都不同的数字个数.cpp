class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int ans = 10, temp = 9;
        for (int i = 0; i < n - 1; i++) {
            temp *= 9 - i;
            ans += temp;
        }
        return ans;
    }
};

/**************************动态规划**********************/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[n + 5];
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - (i - 1));
        }
        return dp[n];
    }
};