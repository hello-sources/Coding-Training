bool isUnique(char* astr){
    int num[128] = {0}, cnt = 0, len = strlen(astr);
    for (int i = 0; astr[i]; i++) {
        num[astr[i]]++;
    }
    if (len == 0 || len == 1) return true;
    for (int i = 0; i < 128; i++) {
        if (num[i] % 2 == 1) cnt++;
    }
    return cnt == len;
}