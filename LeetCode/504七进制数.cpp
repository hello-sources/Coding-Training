char * convertToBase7(int num){
    char *res = (char *)malloc(sizeof(char) * 50);
    int cnt = 0, flag = 0;
    if (num < 0) flag = 1, num = -num;
    if (num == 0) return "0";
    while (num) {
        res[cnt++] = num % 7 + '0';
        num /= 7;
    }
    if (flag) res[cnt++] = '-';
    res[cnt] = '\0';
    for (int i = 0; i  < cnt / 2; i++) {
        char c = res[i];
        res[i] = res[cnt - 1 - i];
        res[cnt - i - 1] = c;
    }
    return res;
}