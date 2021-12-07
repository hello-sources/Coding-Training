bool judge(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[len - 1] > '9' || s[len - 1] < '0') return false;
    }
    return true;
}

bool areNumbersAscending(char * s){
    int len = strlen(s), cnt = 0 ;
    char *res = (char *)malloc(sizeof(char) * 205);
    int num[105] = {0};
    res = strtok(s, " ");
    while (res) {
        if (judge(res)) num[cnt++] = atoi(res);
        res = strtok(NULL, " ");
    }
    for (int i = 0; i < cnt; i++) {
        if ( i - 1 >= 0 && num[i - 1] >= num[i]) return false;
    }
    return true;
}