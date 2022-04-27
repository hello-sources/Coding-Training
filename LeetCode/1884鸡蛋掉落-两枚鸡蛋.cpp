class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = INT_MAX;
            for (int j = 1; j <= i; j++) {
                dp[i] = min(dp[i], max(j, dp[i - j] + 1));
            }
        }
        return dp[n];
    }
};