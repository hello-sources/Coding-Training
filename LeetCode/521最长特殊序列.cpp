int findLUSlength(char * a, char * b){
    int len1 = strlen(a), len2 = strlen(b);
    if (strstr(a, b) == NULL || strstr(b, a) == NULL) return len1 > len2 ? len1 : len2;
    return -1;
}