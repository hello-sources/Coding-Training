/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
    char str[4][12] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    char **res = (char **)malloc(sizeof(char *) * wordsSize);
    res[0] = (char *)malloc(sizeof(char) * 100 * wordsSize);
    for (int i = 1; i < wordsSize; i++) {
        res[i] = res[0] + i * 100;
    }
    int cnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]), cnt0 = 0, cnt1 = 0, cnt2 = 0;
        char *temp = (char *)malloc(sizeof(char) * 105);
        strcpy(temp, words[i]);
        for (int j = 0; j < len; j++) {
            if (temp[j] <= 'Z' && temp[j] >= 'A') temp[j] = temp[j] - 'A' + 'a';
            if (strchr(str[0], temp[j]) != NULL) cnt0++;
            if (strchr(str[1], temp[j]) != NULL) cnt1++;
            if (strchr(str[2], temp[j]) != NULL) cnt2++;
        }
        free(temp);
        if (cnt0 == len || cnt1 == len || cnt2 == len) {
            strcpy(res[cnt++], words[i]);
        }
    }
    *returnSize = cnt;
    return res;
}