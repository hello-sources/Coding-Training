typedef long long ll;

int countVowelPermutation(int n){
    ll ans = 0, mod = 1e9 + 7;
    ll *dp = (ll *)malloc(sizeof(ll) * 5);
    ll *ndp = (ll *)malloc(sizeof(ll) * 5);
    for (int i = 0; i < 5; i++) {
        dp[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
        ndp[1] = (dp[0] + dp[2]) % mod;
        ndp[2] = (dp[1] + dp[3]) % mod;
        ndp[3] = dp[2];
        ndp[4] = (dp[2] + dp[3]) % mod;
        memcpy(dp, ndp, sizeof(ll) * 5);
    }
    for (int i = 0; i < 5; i++) {
        ans = (ans + dp[i]) % mod;
    }
    free(ndp);
    free(dp);
    return ans;
}