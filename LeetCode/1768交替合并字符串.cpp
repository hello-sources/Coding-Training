char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    int i = 0, j = 0;
    char *ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    for (; i < (len1 > len2 ? len2 : len1); i++) {
        ret[j++] = word1[i];
        ret[j++] = word2[i];
    }
    while (i < len1) ret[j++] = word1[i++];
    while (i < len2) ret[j++] = word2[i++];
    ret[j] = '\0';
    return ret;
}