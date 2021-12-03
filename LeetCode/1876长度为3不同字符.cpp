int countGoodSubstrings(char * s){
    int len = strlen(s), ans = 0;
    if (len < 3) return 0;
    for (int i = 0; i < len; i++) {
        if (i - 1 >= 0 && i - 2 >= 0 && s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) ans++;
    }
    return ans;
}