int cuttingRope(int n){
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            max = fmax(max, fmax(j * (i - j), j * dp[i - j]));
        }
        dp[i] = max;
    }
    return dp[n];
}