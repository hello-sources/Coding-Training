bool calc(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans % 2 == 0 ? true : false;
}

int countEven(int num){
    int cnt = 0;
    for (int i = 1; i <= num; i++) {
        if (calc(i)) cnt++;
    }
    return cnt;
}