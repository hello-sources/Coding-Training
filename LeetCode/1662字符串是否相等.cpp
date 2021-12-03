bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    char *ret = (char *)malloc(sizeof(char) * 1005);
    char *res = (char *)malloc(sizeof(char) * 1005);
    int len1 = strlen(word1[0]), len2 = strlen(word2[0]);
    strcpy(ret, word1[0]);
    for (int i = 1; i < word1Size; i++) {
        len1 += strlen(word1[i]);
        strcat(ret, word1[i]);
    }
    strcpy(res, word2[0]);
    for (int i = 1; i < word2Size; i++) {
        len2 += strlen(word2[i]);
        strcat(res, word2[i]);
    }
    ret[len1] = '\0';
    res[len2] = '\0';
    return strcmp(res, ret) == 0;
}