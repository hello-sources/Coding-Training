char * reverseWords(char * s){
    int len = strlen(s);
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    int i = 0;
    while (i < len) {
        int start = i;
        while (i < len && s[i] != ' ') {
            i++;
        }
        for (int k = start; k < i; k++) {
            ret[k] = s[start + i - 1 - k];
        }
        while (i < len && s[i] == ' ') {
            ret[i] = ' ';
            i++;
        }
    }
    ret[len] = '\0';
    return ret;
}
