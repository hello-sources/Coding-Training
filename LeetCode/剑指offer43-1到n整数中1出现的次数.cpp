/******************暴力超时*******************/
int countDigitOne(int n){
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp > 0) {
            if (temp % 10 == 1) cnt += 1;
            temp /= 10;
        }
    }
    return cnt;
}

/*********************找数学规律*********************/
int countDigitOne(int n){
    int  cnt = 0;
    long  digit = 1;
    int high = n / 10, cur = n % 10, low = 0;
    while (high != 0 || cur != 0) {
        if (cur == 0) cnt += digit * high;
        else if (cur == 1) cnt += high * digit + low + 1;
        else cnt += (high + 1) * digit;
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return cnt;
}
