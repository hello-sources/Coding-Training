char* replaceSpace(char* s){
    int len = strlen(s), cnt = 0;
    char *res = (char *)calloc(len * 3 + 5, sizeof(char));
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') res[cnt++] = s[i];
        else {
            strcat(res, "%20");
            cnt += 3;
        }
    }
    res[cnt] = '\0';
    return res;
}