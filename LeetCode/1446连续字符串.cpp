int maxPower(char * s){
    int cnt = 1, ans = 1;
    int len = strlen(s);
    for (int i = 0, j = 1; i < len - 1 && j < len; ) {
        if (s[i++] == s[j++]) {
            cnt++;
            ans = fmax(ans, cnt);
        } else {
            cnt = 1;
        }
    }
    return ans;
}