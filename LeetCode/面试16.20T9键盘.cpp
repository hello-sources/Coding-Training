/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getValidT9Words(char* num, char** words, int wordsSize, int* returnSize){
    int val[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    char **res = (char **)malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    int flag;
    for (int i = 0; i < wordsSize; i++) {
        flag = 0;
        for (int j = 0; j < strlen(words[i]); j++) {
            if (val[words[i][j] - 'a'] != (int)num[j] - '0') {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            res[*returnSize] = (char *)malloc(sizeof(char) * (strlen(words[i]) + 5));
            strcpy(res[(*returnSize)++], words[i]);
        }
    }
    return res;
}