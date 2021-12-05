void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
    return ;
}

char * reverseOnlyLetters(char * s){
    char *res = (char *)malloc(sizeof(char) * 105);
    int len = strlen(s), cnt = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res[cnt++] = s[i];
        }
    }
    res[cnt] = '\0';
    reverse(res);
    cnt = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] >= 'A' && s[i] <= 'Z')) {
            s[i] = res[cnt++];
        }
    }
    free(res);
    return s;
}