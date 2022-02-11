bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int calc(int x) {
    int cnt = 0;
    while (x) {
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

int countPrimeSetBits(int left, int right){
    int ans = 0;
    for (int i = left; i <= right; i++) {
        ans += is_prime(calc(i));
    }
    return ans;
}