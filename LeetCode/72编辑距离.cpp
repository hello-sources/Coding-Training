int minDistance(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    int dp[len1 + 3][len2 + 3];
    memset(dp, 0, sizeof(dp));
    if (len1 * len2 == 0) return len2 + len1;
    for (int i = 0; i < len1 + 1; i++) dp[i][0] = i;
    for (int i = 0; i < len2 + 1; i++) dp[0][i] = i;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int left = dp[i - 1][j] + 1, down = dp[i][j - 1] + 1;
            int temp = dp[i - 1][j - 1];
            if (word1[i - 1] != word2[j - 1]) temp += 1;
            dp[i][j] = fmin(left, fmin(down, temp));
        }
    }
    return dp[len1][len2];
}