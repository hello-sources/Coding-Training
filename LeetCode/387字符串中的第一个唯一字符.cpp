int firstUniqChar(char * s){
    int code[256] = {0};
    for (int i = 0; s[i]; i++) code[s[i]] += 1;
    for (int i = 0; s[i]; i++) if (code[s[i]] == 1) return i;
    return -1;
}