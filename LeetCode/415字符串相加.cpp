//模拟竖式加法
char * addStrings(char * num1, char * num2){
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char *ret = (char *)malloc(sizeof(char) * (fmax(i, j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int ans = x + y + add;
        ret[len++] = ans % 10 + '0';
        add = ans / 10;
        i--;
        j--;
    }
    for (int i = 0; 2 * i < len; i++) {
        int t = ret[i];
        ret[i] = ret[len - i - 1];
        ret[len - i - 1] = t;
    }
    ret[len++] = '\0';
    return ret;
}