//利用栈的思想
int balancedStringSplit(char * s){
    int ans = 0, len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'L') cnt++;
        else cnt--;
        if (cnt == 0) {
            ans++;
        }
    }
    return ans;
}