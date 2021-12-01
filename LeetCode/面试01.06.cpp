//sprintf都忘了啊，什么鬼
char* compressString(char* S){
    int len1 = strlen(S);
    if (len1 <= 1) return S;
    int cur = 0, cnt = 1;
    char *ret = (char *)malloc(sizeof(char) * (2 * len1) + 1);
    for (int i = 1; i < len1 + 1; i++) {
        if (S[i] == S[i - 1]) {
            cnt++;
        } else {
            ret[cur++] = S[i - 1];
            int wlen = sprintf(&ret[cur], "%d", cnt);
            cur += wlen;
            cnt = 1;
        }
    }
    ret[cur] = '\0';
    if (strlen(ret) >= len1) return S;
    return ret;
}