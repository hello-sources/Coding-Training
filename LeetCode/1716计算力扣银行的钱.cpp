int totalMoney(int n){
    int weeks = n / 7, last = n % 7;
    if (weeks == 0) return (1 + last) * last / 2;
    int ans = 0;
    for (int i = 0; i < weeks; i++) {
        ans += 28 + 7 * i;
    }
    if (last == 0) return ans;
    return ans + (weeks + 1 + last + weeks) * last / 2;
}