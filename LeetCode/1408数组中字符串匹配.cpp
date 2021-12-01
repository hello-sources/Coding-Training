/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** stringMatching(char ** words, int wordsSize, int* returnSize){
    char **ret = (char **)calloc(wordsSize, sizeof(char *));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        int cnt = 1;
        for (int j = 0; j < wordsSize; j++) {
            if (strstr(words[j], words[i]) != NULL) cnt += 1;
        }
        if (cnt > 2) ret[(*returnSize)++] = words[i];
    }
    return ret;
}