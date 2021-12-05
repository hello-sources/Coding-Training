int findString(char** words, int wordsSize, char* s){
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(s, words[i]) == 0) return i;
    }
    return -1;
}