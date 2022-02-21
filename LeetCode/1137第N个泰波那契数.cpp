int tribonacci(int n){
    int a = 0, b = 1, c = 1, d;
    if (n < 2) return n;
    if (n == 2) return 1;
    int i = 2;
    while (i < n) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
        i++;
    }
    return d;
}