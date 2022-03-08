int minOperations(int n){
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = 2 * i + 1;
        if (temp > n) ans += temp - n;
    }
    return ans;
}