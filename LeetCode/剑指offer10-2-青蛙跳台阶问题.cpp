int ans = 1, first = 0, second = 0;
    for (int i = 1; i <= n; i++) {
        first = second;
        second = ans;
        ans = first + second;
        ans %= 1000000007;
    }
    return ans % 1000000007;