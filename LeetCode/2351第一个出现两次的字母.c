char repeatedCharacter(char * s){
    int len = strlen(s);
    int *cnt = (int *)malloc(sizeof(int) * 26);
    memset(cnt, 0, sizeof(int) * 26);
    for (int i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] > 1) return s[i];
    } 
    return NULL;
}