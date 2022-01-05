double calc(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    double ans = 1.0;
    ans = calc(x, n / 2);
    return n % 2 == 0 ? ans * ans : ans * ans * x;
}

double myPow(double x, int n){
    if (x == 0 && n < 0) return 0.0;
    return  n > 0 ? calc(x, n) : 1 / calc(x, n);
}