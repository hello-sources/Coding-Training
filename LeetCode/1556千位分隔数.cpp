char * thousandSeparator(int n){
    int cnt = 0, j = 0, temp = n, len;
    if (n == 0) return "0";
    char *res = (char *)malloc(sizeof(char) * 25);
    while (temp) {
        if (j % 3 == 0 && j != 0) {
            res[cnt++] = '.';
        }
        res[cnt++] = (temp % 10) + '0';
        j++;
        temp /= 10;
    }a
    res[cnt] = '\0';
    len = strlen(res);
    for (int i = 0; i < len / 2; i++) {
        char ch = res[i];
        res[i] = res[len - 1 - i];
        res[len - 1 - i] = ch;
    }
    return res;
}