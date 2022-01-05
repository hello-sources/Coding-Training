int integerBreak(int n){
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= n; i++) {
        int cur = 0;
        for (int j = 0; j < i; j++) {
            cur = fmax(cur, fmax(j * (i - j), j * dp[i - j]));
        }
        dp[i] = cur;
    }
    return dp[n];
}