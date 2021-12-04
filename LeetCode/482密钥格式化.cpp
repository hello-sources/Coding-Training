char * licenseKeyFormatting(char * s, int k){
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len * 2 + 1));
    char *ret = (char *)malloc(sizeof(char) * (len * 2 + 1));
    int cntc = 0, cnt = 0, left = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            res[cnt++] = s[i] - 'a' + 'A';
        } else if ((s[i] >= '0' && s[i] <= '9') || (s[i] <= 'Z' && s[i] >= 'A')) {
            res[cnt++] = s[i];
        }
    }
    int i = 0, j = cnt % k;
    while ((i < cnt % k) && (cnt % k != 0)) {
        ret[i] = res[i];
        i++;
    }
    while (j < cnt) {
        if ((j - cnt % k) % k == 0 && j != 0) ret[i++] = '-';
        ret[i++] = res[j];
        j++; 
    }
    free(res);
    ret[i] = '\0';
    return ret;
}