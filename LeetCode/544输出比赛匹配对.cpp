char res[5000][50000];
char * findContestMatch(int n){
    for (int i = 0; i <= n; i++) {
        sprintf(res[i], "%d", i);
    }
    char temp[50000];
    while (n > 0) {
        for (int i = 1, j = n; i < j; i++, j--) {
            sprintf(temp, "(%s,%s)", res[i], res[j]);
            strcpy(res[i], temp);
        }
        n /= 2;
    }
    return res[1];
}