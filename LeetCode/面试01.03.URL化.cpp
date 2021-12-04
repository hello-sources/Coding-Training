char* replaceSpaces(char* S, int length){
    char *res = (char *)malloc(sizeof(char) * 5000005);
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        if (S[i] != ' ') res[cnt++] = S[i];
        else {
            res[cnt++] = '%';
            res[cnt++] = '2';
            res[cnt++] = '0';
        }
    }
    res[cnt] = '\0';
    return res;
}

//节省空间的另一种做法
char* replaceSpaces(char* S, int length){
    int len = strlen(S) - 1;
    for (int i = length - 1; i >= 0; i--) {
        if (S[i] == ' ') {
            S[len--] = '0';
            S[len--] = '2';
            S[len--] = '%';
        } else {
            S[len--] = S[i];
        }
    }
    return S + len + 1;
}