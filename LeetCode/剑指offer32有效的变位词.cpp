bool isAnagram(char * s, char * t){
    if (strcmp(s, t) == 0) return false;
    int len = strlen(s), len2 = strlen(t);
    if (len != len2) return false;
    int num[26] = {0};
    int num2[26] = {0};
    for (int i = 0; i < len; i++) {
        num[s[i] - 'a']++;
    }
    for (int i = 0; i < len2; i++) {
        num2[t[i] - 'a']++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if (num[i] != num2[i]) return false;
    }
    return true;
}