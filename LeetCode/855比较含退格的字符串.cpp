//使用栈的思想，当有#出现的时候，就把栈里面的内容弹出来
char *check(char *s) {
    int len = strlen(s), cnt = 0;
    char *ret = (char *)malloc(sizeof(char) * (len + 5));
    for (int i = 0; i < len; i++) {
        if (s[i] != '#') {
            ret[cnt++] = s[i];
        } else if (cnt > 0) {
            cnt--;
        }
    }
    ret[cnt] = '\0';
    return ret;
}

bool backspaceCompare(char * s, char * t){
    return strcmp(check(s), check(t)) == 0;
}