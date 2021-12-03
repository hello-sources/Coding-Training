int getLucky(char * s, int k){
    int len = strlen(s), ans = 0, temp = 0;
    for (int i = 0; i < len; i++) {
        temp = s[i] - 'a' + 1;
        while (temp) {
            ans += temp % 10;
            temp /= 10;
        }
    }
    if (k == 1) return ans;
    int cnt = 1;
    while (cnt < k) {
        temp = ans;
        ans = 0;
        while (temp > 0) {
            ans += temp % 10;
            temp /= 10;
        }
        cnt++;
    }
    return ans;
}