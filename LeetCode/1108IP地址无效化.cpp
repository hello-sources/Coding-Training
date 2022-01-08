char * defangIPaddr(char * address){
    int len = strlen(address);
    char *res = (char *)malloc(sizeof(char) * (len * 5));
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (address[i] != '.') res[cnt++] = address[i];
        else {
            res[cnt++] = '[';
            res[cnt++] = '.';
            res[cnt++] = ']';
        }
    }
    res[cnt] = '\0';
    return res;
}