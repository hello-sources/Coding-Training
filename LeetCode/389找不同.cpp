char findTheDifference(char * s, char * t){
    int num[26] = {0};
    int lens = strlen(s), lent = strlen(t);
    for (int i = 0; i < lens; i++) {
        num[s[i] - 'a']++;
    }
    for (int i = 0; i < lent; i++) {
        num[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (num[i] % 2 == 1) {
            return i + 'a';
        }
    }
    return ' ';
}