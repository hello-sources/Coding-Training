bool isPalindrome(char * s){
    int len = strlen(s), cnt = 0, flag = 0;
    char *res = (char *)malloc(sizeof(char) * (len + 5));
    for (int i = 0; i < len; i++) {
        if ((s[i] <= '9' && s[i] >= '0') || (s[i] <= 'z' && s[i] >= 'a')) res[cnt++] = s[i];
        if (s[i] <= 'Z' && s[i] >= 'A') {
            res[cnt++] = s[i] - 'A' + 'a';
        }
    }
    for (int i = 0; i < cnt / 2; i++) {
        if (res[i] != res[cnt - 1 - i]) flag = 1;
    }
    free(res);
    return flag == 0;
}