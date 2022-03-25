int getStep(int cur, int n) {
    int step = 0;
    long first = cur, last = cur;
    while (first <= n) {
        step += fmin(last, n) - first + 1;
        first *= 10;
        last = last * 10 + 9;
    }
    return step;
}

int findKthNumber(int n, int k){
    k--;
    int cur = 1;
    while (k > 0) {
        int step = getStep(cur, n);
        if (step <= k) {
            k -= step;
            cur++;
        } else {
            k--;
            cur *= 10;
        }
    }
    return cur;
}