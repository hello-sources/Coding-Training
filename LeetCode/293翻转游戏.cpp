/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generatePossibleNextMoves(char * currentState, int* returnSize){
    int len = strlen(currentState);
    *returnSize = 0;
    if (len == 0) {
        return NULL;
    }
    char **res = (char **)malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++) {
        if (currentState[i] == '+' && currentState[i + 1] == '+') {
            res[(*returnSize)] = (char *)malloc(sizeof(char) * (len + 1));
            strcpy(res[(*returnSize)], currentState);
            res[(*returnSize)][i] = '-';
            res[(*returnSize)++][i + 1] = '-';
        }
    }
    return res;
}