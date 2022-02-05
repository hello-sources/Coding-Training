int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int countBalls(int lowLimit, int highLimit){
    int cnt[50] = {0};
    for (int i = lowLimit; i <= highLimit; i++) {
        int temp = i, ans = 0;
        while (temp) {
            ans += temp % 10;
            temp /= 10;
        }
        cnt[ans]++;
    }
    qsort(cnt, 50, sizeof(int), cmp);
    return cnt[0];
}