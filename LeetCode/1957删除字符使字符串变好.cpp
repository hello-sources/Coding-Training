char * makeFancyString(char * s){
    int len = strlen(s);
    if (len < 3) return s;
    char *ret = (char *)malloc(sizeof(char) * (len + 5));
    ret[0] = s[0];
    ret[1] = s[1];
    int i = 2;
    for (int j = 2; s[j]; j++) {
        if (s[j] != s[j - 1] || s[j] != s[j - 2]) {
            ret[i++] = s[j];
            continue;
        }
    }
    ret[i] = '\0';
    return ret;
}