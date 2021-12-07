char * reformatNumber(char * number){
    int len = strlen(number), cnt = 0, ind = 0;
    char *res = (char *)malloc(sizeof(char) * (len * 2));
    if (len < 3) return number;
    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] == ' ' || number[i] == '-') continue;
        if (cnt % 4 == 3)  res[cnt++] = '-';
        res[cnt++] = number[i];
    }
    if (cnt % 4 == 1) {
        char ch = res[cnt - 3];
        res[cnt - 3] = '-', res[cnt - 2] = ch; 
    }
    res[cnt] = '\0';
    return res;
}