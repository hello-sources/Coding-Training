int countDigitOne(int n){
    long digit = 1;
    int low = 0, cnt = 0, high = n / 10, cur = n % 10;
    while (high != 0 || cur != 0) {
        if (cur == 0) cnt += high * digit;
        else if (cur == 1) cnt += high * digit + low + 1;
        else cnt += (high + 1) * digit;
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return cnt;
}