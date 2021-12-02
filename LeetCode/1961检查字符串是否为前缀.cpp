bool isPrefixString(char * s, char ** words, int wordsSize){
    char *temp = (char *)calloc(strlen(s) + 2005, sizeof(char));
    int cnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        cnt += strlen(words[i]);
        temp[cnt] = '\0';
        strcat(temp, words[i]);
        if (strcmp(s, temp) == 0) return true;
    }
    return false;
}