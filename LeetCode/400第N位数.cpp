int findNthDigit(int n){
    int d = 1, cnt = 9;
    while (n > (long long)d * cnt) {
        n -= d * cnt;
        d++;
        cnt *= 10;
    }
    int ind = n - 1, start = pow(10, d - 1);
    int num = start + ind / d, digit_ind = ind % d;
    return (num / ((int)pow(10, d - digit_ind - 1))) % 10;
}