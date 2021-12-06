int canBeTypedWords(char * text, char * brokenLetters){
    int cnt = 0, len = strlen(text);
    char *res = (char *)malloc(sizeof(char) * (len + 5));
    res = strtok(text, " ");
    while (res) {
        int flag = 1;
        for (int i = 0; i < strlen(brokenLetters); i++) {
            if (strchr(res, brokenLetters[i]) != NULL) {
                flag = 0;
                break;
            }
        }
        cnt += flag;
        res = strtok(NULL, " ");
    }
    free(res);
    return cnt;
}