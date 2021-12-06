bool detectCapitalUse(char * word){
    int cnt = 0, len = strlen(word);
    for (int i = 0; word[i]; i++) {
        if (word[i] <= 'Z' && word[i] >= 'A') cnt++;
    }
    if (cnt == 0 || (cnt == 1 && (word[0] <= 'Z' && word[0] >= 'A'))) return true;
    if (cnt == len) return true;
    return false;
}