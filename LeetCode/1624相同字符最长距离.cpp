int maxLengthBetweenEqualCharacters(char * s){
    int ans = -1, len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[j]  != s[i]) continue;
            ans = fmax(ans, j - i - 1);
        }
    }
    if (ans == -1) return -1;
    return ans;
}