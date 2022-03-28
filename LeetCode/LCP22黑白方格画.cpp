int calc(int x, int y) {
    if (x == 0) return 1;
    int cnt = 1;
    for (int i = 0; i < x; i++) {
        cnt *= (y - i);
    }
    for (int i = 1; i <= x; i++) {
        cnt /= i;
    }
    return cnt;
}

int paintingPlan(int n, int k){
    if (k == 0 || k == n * n) return 1;
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i * n + j * n - i * j == k) {
                cnt += calc(i, n) * calc(j, n);
            }
        }
    }
    return cnt;
}