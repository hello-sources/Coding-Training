bool judge(char *words) {
    int len = strlen(words);
    for (int i = 0; i < len / 2; i++) {
        if (words[i] != words[len - 1 - i]) return false;
    }
    return true;
}

char * firstPalindrome(char ** words, int wordsSize){
    for (int i = 0; i < wordsSize; i++) {
        if (judge(words[i])) return words[i];
    }
    return "";
}