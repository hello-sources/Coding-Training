char * sortSentence(char * s){
    int len = strlen(s);
    char *ans = (char *)malloc(sizeof(char) * len);
    char word[9][201] = {0};
    int cnt = 0, cal = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') cnt = 0;
        else {
            if (s[i] <= '9' && s[i] >= '1') {
                cal++;
                for (int j = 0; j < cnt; j++) {
                    word[s[i] - '1'][j] = ans[j];
                }
            } else {
                ans[cnt++] = s[i];
            }
        }
    }
    int index = 0;
    for (int i = 0; i < cal; i++) {
        int j =0;
        while (word[i][j]) {
            s[index++] = word[i][j++];
        }
        s[index++] = ' ';
    }
    s[--index] = '\0';
    return s;
}