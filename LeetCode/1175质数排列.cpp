long calc(int x) {
    if (x == 1) return 1;
    long temp = 1;
    while (x) {
        temp *= x;
        x--;       
        temp %= 1000000007;
    }
    return temp % 1000000007;
}

bool is_prime(int x) {
    if (x == 1) return false;
    if (x == 2 || x == 3) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int numPrimeArrangements(int n){
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) cnt++;
    }
    long long ans = calc(cnt) * calc(n - cnt) % 1000000007;
    return ans;
}