int longestPalindromeSubseq(char * s){
    int len = strlen(s);
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) dp[i][i] = 1;
    for (int i = len - 1; i >= 0; i--) {
        char ch = s[i];
        for (int j = i + 1; j < len; j++) {
            char ch2 = s[j];
            if (ch == ch2) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = fmax(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[0][len - 1];
}