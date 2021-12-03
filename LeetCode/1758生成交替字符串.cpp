int minOperations(char * s){
    int len = strlen(s);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0 && s[i] != '0') cnt0++;
        if (i % 2 != 0 && s[i] == '0') cnt0++;
    }
    for (int i = 0; i < len; i++) {
        if (i % 2 != 0 && s[i] == '1') cnt1++;
        if (i % 2 == 0 && s[i] != '1') cnt1++;
    }
    return fmin(cnt1, cnt0);
}