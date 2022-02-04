int findMinFibonacciNumbers(int k){
    int f[100], ind = 0, a = 1, b = 1, ans = 0;
    f[ind++] = 1;
    while (a + b <= k) {
        int c = a + b;
        f[ind++] = c;
        a = b;
        b = c;
    }
    for (int i = ind - 1; i >= 0 && k > 0; i--) {
        int temp = f[i];
        if (k >= temp) {
            k -= temp;
            ans++;
        }
    }
    return ans;
}