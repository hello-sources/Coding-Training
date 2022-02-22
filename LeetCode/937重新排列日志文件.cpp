/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    int i = 0, j = 0;
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    while (*(s1 + i++) != ' ');
    while (*(s2 + j++) != ' ');
    if (*(s1 + i) <= '9' && *(s1 + i) >= '0' && *(s2 + j) <= '9' && *(s2 + j) >= '0') return 0;
    if (*(s1 + i) <= 'z' && *(s1 + i) >= 'a' && *(s2 + j) <= 'z' & *(s2 + j) >= 'a') {
        for ( ; *(s1 + i) != '\0' && *(s2 + j) != '\0' && *(s1 + i) == *(s2 + j); i++, j++);
        if (i == j && *(s1 + i) == *(s2 + j)) {
            i = j = 0;
            for ( ; *(s1 + i) != '\0' && *(s2 + j) != '\0' && *(s1 + i) == *(s2 + j); i++, j++);
        }
        return *(s1 + i) - *(s2 + j);
    }
    if (*(s1 + i) >= 'a' && *(s1 + i) <= 'z') return -1;
    return 1;
}

char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    *returnSize = logsSize;
    qsort(logs, logsSize, sizeof(*(logs)), cmp);
    return logs;
}