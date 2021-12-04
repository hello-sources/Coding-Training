char firstUniqChar(char* s){
    int len = strlen(s);
    int num[26] = {0};
    for (int i = 0; i < len; i++) {
        num[s[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (num[s[i] - 'a'] == 1) return s[i];
    }
    return ' ';
}
