bool divisorGame(int n){
    return n % 2 == 0;
}

/*****************DP问题*****************/
bool divisorGame(int n){
    int f[n + 5];
    memset(f, 0, sizeof(f));
    f[1] = false, f[2] = true;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0 && !f[i - j]) {
                f[i] = true;
                break;
            }
        }
    }
    return f[n];
}