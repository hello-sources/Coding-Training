char * truncateSentence(char * s, int k){
    int cnt = 0, len = strlen(s), temp = 0;
    char *res = (char *)malloc(sizeof(char) * (len + 5));
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') temp++;
        if (temp == k) break;
        res[cnt++] = s[i];
    }
    res[cnt] = '\0';
    return res;
}