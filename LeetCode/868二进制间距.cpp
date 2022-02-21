int binaryGap(int n){
    int max = INT_MIN, cnt = 0;
    while (n >= 1) {
        if (n % 2 == 1) {
            if (cnt > 0) max = fmax(max, cnt);
            cnt = 1;
        }
        else {
            if (cnt > 0) cnt++;
        }
        n /= 2;
    }
    return max;
}