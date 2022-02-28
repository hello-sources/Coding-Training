char * encode(int num){
    num++;
    char *res = (char *)malloc(sizeof(char) * 33);
    int cnt = 0, ind = 0;
    char temp[33] = {0};
    while (num > 0) {
        temp[cnt++] = (num & 1) + '0';
        num >>= 1;
    }
    for (int i = cnt - 2; i >= 0; i--) {
        res[ind++] = temp[i];
    }
    res[ind] = '\0';
    return res;
}