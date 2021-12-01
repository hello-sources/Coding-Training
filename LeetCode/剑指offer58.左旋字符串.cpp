char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char *ret = (char *)malloc(sizeof(char) * (len + 5));
    int j = 0;
    ret[n] = 0;
    for (int i = n; i < len; i++) {
        ret[j++] = s[i];
    }
    s[n] = '\0';
    for (int i = 0; i < n; i++) {
        ret[j++] = s[i];
    }
    ret[len] = '\0';
    return ret;
}