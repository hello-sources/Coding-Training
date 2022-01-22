int findNthDigit(int n){
    int d = 1, cnt = 9;
    while (n > (long long) d * cnt) {
        n -= d * cnt;
        d++;
        cnt *= 10;
    }
    int ind = n - 1, start = (int)pow(10, d - 1);
    int digit_cnt = ind % d, num = start + ind / d;
    return (num / (int)pow(10, d - digit_cnt - 1)) % 10;
}