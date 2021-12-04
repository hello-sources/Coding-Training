char * removeOuterParentheses(char * s){
    int len = strlen(s), cnt = 0, j = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            cnt++;
            if (cnt > 1) s[j++] = '(';
        } else {
            cnt--;
            if (cnt > 0) s[j++] = ')';
        }
    }
    s[j] = '\0';
    return s;
}