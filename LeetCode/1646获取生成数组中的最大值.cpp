int getMaximumGenerated(int n){
    if (n <= 1) return n;
    int num[n + 1];
    memset(num, 0, sizeof(num));
    num[0] = 0, num[1] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        num[i] = num[i / 2] + i % 2 * num[i / 2 + 1];
        res = fmax(num[i], res);
    }
    return res;
}