void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
    return ;
}

char * reversePrefix(char * word, char ch){
    int len = strlen(word), cnt = 0;
    char *res = (char *)malloc(sizeof(char) * (len + 5));
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] != ch) res[cnt++] = word[i];
        else if (word[i] == ch) {
            flag = 1;
            res[cnt++] = word[i];
            break;
        }
    } 
    if (flag == 0) return word;
    res[cnt] = '\0';
    reverse(res);
    for (int i = cnt; i < len; i++) {
        res[cnt++] = word[i];
    }
    res[len] = '\0';
    return res;
}