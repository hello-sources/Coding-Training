/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    char **res = (char **)malloc(sizeof(char *) * 1005);
    char **temp = (char **)malloc(sizeof(char *) * 1005);
    char *tok = strtok(text, " ");;
    int index = 0, cnt = 0;
    while (tok) {
        temp[index] = (char *)calloc(15, sizeof(char));
        strcpy(temp[index++], tok);
        tok = strtok(NULL, " ");
    }
    for (int i = 1; i < index - 1; i++) {
        if (strcmp(first, temp[i - 1]) == 0 && strcmp(second, temp[i]) == 0) {
            res[cnt] = (char *)calloc(15, sizeof(char));
            strcpy(res[cnt++], temp[i + 1]);
        }
    }
    *returnSize = cnt;
    return res;
}