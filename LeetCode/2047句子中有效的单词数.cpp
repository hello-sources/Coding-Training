bool judge(char *s) {
    int len = strlen(s), cnt1 = 0, cnt2 = 0;
    if (strcmp(s, "!") == 0) return 1;
    for (int i = 0; i < len; i++) {
        if (s[i] <= '9' && s[i] >= '0') return false;
        if (s[i] == '-') {
            if (i - 1 >= 0 && (s[i - 1] >= 'a' && s[i - 1] <= 'z') && i + 1 < len && s[i + 1] <= 'z' && s[i + 1] >= 'a') cnt1++;
            else return false;
        }
        if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
            cnt2++;
            if (i != len - 1) return false;
        }
        if (cnt1 > 1 || cnt2 > 1) return false;
    }
    return true;
}

int countValidWords(char * sentence){
    char *res = (char *)malloc(sizeof(char) * 100);
    int cnt = 0;
    res = strtok(sentence, " ");
    while (res) {
        cnt += judge(res);
        res = strtok(NULL, " ");
    }
    return cnt;
}