int countCharacters(char ** words, int wordsSize, char * chars){
    int num[105] = {0}, ans = 0, len = strlen(chars);
    char *temp = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < wordsSize; i++) {
        memcpy(temp, chars, sizeof(char) * len);
        int cnt = 0, tlen = strlen(words[i]);
        for (int j = 0; j < tlen; j++) {
            for (int k = 0; k < len; k++) {
                if (words[i][j] != temp[k]) continue;
                temp[k] = '0';
                cnt++;
                break;
            }
        }
        if (cnt == tlen) ans += tlen;
    }
    free(temp);
    return ans;
}