bool isThree(int n){
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != n / i) cnt += 2;
            else cnt += 1;
        }
    }
    return cnt == 3;
}