int numOfStrings(char ** patterns, int patternsSize, char * word){
    int cnt = 0;
    for (int i = 0; i < patternsSize; i++) {
        if (strstr(word, patterns[i]) != NULL) cnt += 1;
    }
    return cnt;
}