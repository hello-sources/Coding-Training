bool rotateString(char * s, char * goal){
    int len1 = strlen(s), len2 = strlen(goal);
    if (len1 != len2) return false;
    char *ret = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    int i = 0;
    for ( ; i < 2 * len1; i++) {
        ret[i] = s[i % len1];
    }
    ret[i] = '\0';
    if (strstr(ret, goal) != NULL) return true;
    return false;
}