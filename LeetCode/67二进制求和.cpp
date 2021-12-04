void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
    return ;
}

char * addBinary(char * a, char * b){
    int lena = strlen(a), lenb = strlen(b);
    reverse(a), reverse(b);
    int n = fmax(lenb, lena), len = 0, cnt = 0;
    char *res = (char *)malloc(sizeof(char) * (n + 2));
    for (int i = 0; i < n; i++) {
        cnt += i < lena ? (a[i] == '1') : 0;
        cnt += i < lenb ? (b[i] == '1') : 0;
        res[len++] = cnt % 2 + '0';
        cnt /= 2;
    }
    if (cnt) {
        res[len++] = '1';
    }
    res[len] = '\0';
    reverse(res);
    return res;
}