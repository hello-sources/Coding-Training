class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        int len = s.size();
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[0][1] = s[0] == '1' ? 0 : 1;
        for (int i = 1; i < len; i++) {
            int cnt0 = dp[0][(i - 1) % 2];
            int cnt1 = dp[1][(i - 1) % 2];
            dp[0][i % 2] = cnt0 + (s[i] == '0' ? 0 : 1);
            dp[1][i % 2] = min(cnt0, cnt1) + (s[i] == '1' ? 0 : 1);
        }
        return min(dp[0][(len - 1) % 2], dp[1][(len - 1) % 2]);
    }
};