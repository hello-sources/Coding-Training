//strtok用法
int isPrefixOfWord(char * sentence, char * searchWord){
    char *res = (char *)calloc(105, sizeof(char));
    res = strtok(sentence, " ");
    int cnt = 1;
    while (res) {
        if (strstr(res, searchWord) == res) return cnt;
        cnt++;
        res = strtok(NULL, " ");
    }
    free(res);
    return -1;
}