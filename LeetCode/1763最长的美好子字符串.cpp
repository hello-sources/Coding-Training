//暴力枚举每一段字符串长度，然后判断对应字符串长度是否为美好字符串
bool isValid(char *s, int l, int r) {
    int small[26] = {0};
    int big[26] = {0};
    for (int i = l; i <= r; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            small[s[i] - 'a']++;
        } else {
            big[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if ((small[i] == 0 && big[i] != 0) || (small[i] != 0 && big[i] == 0)) return false;
    }
    return true;
}

char * longestNiceSubstring(char * s) {  
    int left = 0, right = 0, cnt = 0;
    for (int i = 0; s[i]; i++) {
        for (int j =  i + 1; s[j]; j++) {
            if (isValid(s, i, j) && j - i + 1 > cnt) {
                left = i;
                right = j;
                cnt = j - i + 1;
            }
        }
    }
    char *ret = (char *)calloc(cnt + 5, sizeof(char));
    int i = 0;
    for (; i < cnt; i++) {
        ret[i] = s[left++];
    }
    ret[i] = '\0';
    return ret;
}