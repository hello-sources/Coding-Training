int lastRemaining(int n){
    int cnt = n, k = 0;
    int a1 = 1, step = 1;
    while (cnt > 1) {
        if (k % 2 == 0) {
            a1 += step;
        } else {
            a1 = (cnt % 2 == 0) ? a1 : a1 + step;
        }
        k++;
        cnt >>= 1;
        step <<= 1;
    }
    return a1;
}