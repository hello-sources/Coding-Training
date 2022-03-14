int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1), len2 = strlen(text2);
    int dp[len1 + 5][len2 + 5];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len1; i++) {
        char ch = text1[i - 1];
        for (int j = 1; j <= len2; j++) {
            char ch2 = text2[j - 1];
            if (ch == ch2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}