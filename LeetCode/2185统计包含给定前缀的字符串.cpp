bool judge(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 < len2) return false;
    for (int i = 0; i < len2; i++) {
        if (t[i] == s[i]) continue;
        else return false;
    }
    return true;
}

int prefixCount(char ** words, int wordsSize, char * pref){
    int cnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (judge(words[i], pref)) cnt++;
    }
    return cnt;
}