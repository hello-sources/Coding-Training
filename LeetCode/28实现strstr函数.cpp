int strStr(char * haystack, char * needle){
    if (needle == NULL) return 0;
    int len1 = strlen(haystack), len2 = strlen(needle);
    for (int i = 0; i + len2 <= len1; i++) {
        bool flag = true;
        for (int j = 0; j < len2; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return -1;
}