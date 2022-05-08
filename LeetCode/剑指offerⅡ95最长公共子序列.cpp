class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            char ch1 = text1[i - 1];
            for (int j = 1; j <= len2; j++) {
                char ch2 = text2[j - 1];
                if (ch2 == ch1) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1][len2];
    }
};