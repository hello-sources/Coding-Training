bool isAlienSorted(char ** words, int wordsSize, char * order){
    int hash[26] = {0};
    for (int i = 0; i < strlen(order); i++) {
        hash[order[i] - 'a'] = i;
    }
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            if (words[i][j] == '\0' || words[i + 1][j] == '\0') return false;
            if (words[i][j] == words[i + 1][j]) continue;
            else if (hash[words[i][j] - 'a'] > hash[words[i + 1][j] - 'a']) return false;
            else if (hash[words[i][j] - 'a'] < hash[words[i + 1][j] - 'a']) break;
        }
    }
    return true;
}