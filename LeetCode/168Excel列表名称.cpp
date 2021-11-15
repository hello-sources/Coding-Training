char *rev(char *ans, int cnt) {
    char temp;
    for (int i = 0; i < cnt / 2; i++) {
        temp = ans[i];
        ans[i] = ans[cnt - i - 1];
        ans[cnt - i - 1] = temp;
    }
    return ans;
}

char * convertToTitle(int columnNumber){
    char *ans = (char *)malloc(sizeof(char) * 10);
    int cnt = 0;
    while (columnNumber > 0) {
        int temp = (columnNumber - 1) % 26 + 1;
        ans[cnt++] = temp + 'A' - 1;
        columnNumber = (columnNumber - temp) / 26;
    }
    ans[cnt] = '\0';
    return rev(ans, cnt);
}