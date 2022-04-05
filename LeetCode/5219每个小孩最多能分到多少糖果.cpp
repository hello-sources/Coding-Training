/**********************超时******************8*/
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maximumCandies(int* candies, int candiesSize, long long k){
    long long ans = 0;
    for (int i = 0; i < candiesSize; i++) {
        ans += candies[i];
    }
    if (ans / k == 0) return 0;
    int max = ans / k;
    qsort(candies, candiesSize, sizeof(int), cmp);
    for (int t = max; t >= 1; t--) {
        long long cnt = 0;
        for (int i = 0; i < candiesSize; i++) {
            cnt += candies[i] / t;
            if (cnt >= k) return t;
        }
        if (cnt >= k) return t;
    }
    return 0;
}

/*************************二分优化************************/
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

bool calc(int mid, long long k, int *candies, int candiesSize) {
    long long cnt = 0;
    for (int i = 0; i < candiesSize; i++) {
        cnt += candies[i] / mid;
        if (cnt >= k) return true;
    }
    return false;
}

int maximumCandies(int* candies, int candiesSize, long long k){
    long long ans = 0;
    for (int i = 0; i < candiesSize; i++) {
        ans += candies[i];
    }
    if (ans / k == 0) return 0;
    int max = ans / k;  
    int l = 1, r = max;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (calc(mid, k, candies, candiesSize)) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}