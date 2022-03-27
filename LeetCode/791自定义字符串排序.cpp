char * customSortString(char * order, char * s){
    int len = strlen(s), size = 0, length = strlen(order);
    char *res = (char *)malloc(sizeof(char) * (len + 5));
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < len; j++) {
            if (s[j] == order[i]) {
                res[size++] = s[j];
                s[j] = '-';
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == '-') continue;
        res[size++] = s[i];
    }
    res[size] = '\0';
    return res;
}