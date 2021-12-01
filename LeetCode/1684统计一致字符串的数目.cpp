//strchr的使用
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]), cnt = 0;
        for (int j = 0; j < len; j++) {
            if (strchr(allowed, words[i][j]) != NULL) cnt++;
        }
        if (cnt == len) ans += 1;
    }
    return ans;
}