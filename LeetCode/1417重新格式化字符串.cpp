char * reformat(char * s){
    int len = strlen(s), num = 0, cnum = 0;
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 0; s[i]; i++) {
        if (s[i] <= '9' && s[i] >= '0') {
            num++;
        } else {
            cnum++;
        }
    }
    if (abs(num - cnum) > 1) return "";
    int t0 = 0, t1 = 0;
    if (num > cnum) {
        for (int i = 0; i < len; i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                ret[2 * (t0++)] = s[i];
            } else {
                ret[2 * (t1++) + 1] = s[i];
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (s[i] <= 'z' && s[i] >= 'a') {
                ret[2 * (t0++)] = s[i];
            } else {
                ret[2 * (t1++) + 1] = s[i];
            }
        }
    }
    ret[len] = '\0';
    return ret;
}