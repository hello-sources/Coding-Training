class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = len1 - 1; i >= 0; i--) dp[i][len2] = dp[i + 1][len2] + (int)s1[i];
        for (int i = len2 - 1; i >= 0; i--) dp[len1][i] = dp[len1][i + 1] + (int)s2[i];
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) dp[i][j] = dp[i + 1][j + 1];
                else {
                    dp[i][j] = min(dp[i + 1][j] + (int)s1[i], dp[i][j + 1] + (int)s2[j]);
                }
            }
        }
        return dp[0][0];
    }
};