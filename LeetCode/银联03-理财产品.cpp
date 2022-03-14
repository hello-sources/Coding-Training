int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxInvestment(int* product, int productSize, int limit){
    qsort(product, productSize, sizeof(int), cmp);
    long *num = (long *)malloc(sizeof(long) * 100005);
    memset(num, 0, sizeof(num));
    long ans = 0, sum = 0, cnt;
    for (int i = 0; i < productSize; i++) {
        int temp = (product[i] + 1) * product[i] / 2;
        sum += temp;
        num[i] += temp;
        
    }
    if (sum <= limit) return sum;
    else cnt = sum - limit;
    int t = 1;
    while (cnt >= 0) {
        for (int i = 0; i < productSize; i++) {
            if (num[i] < t) continue;
            num[i] -= t;
            cnt--;
        }
        t++;
    }
    
    for (int i = 0; i < productSize; i++) {
        ans += num[i];
        ans %= 1000000007;
    }
    return ans;
}