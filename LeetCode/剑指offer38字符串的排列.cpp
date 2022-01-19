/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char ** rec, int *returnSize, int *vis, char *s, int i, int len, char *temp) {
    if (i == len) {
        char *tmp = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(tmp, temp);
        rec[(*returnSize)++] = tmp;
        return ;
    }
    for (int j = 0; j < len; j++) {
        if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
            continue;
        }
        vis[j] = true;
        temp[i] = s[j];
        backtrack(rec, returnSize, vis, s, i + 1, len, temp);
        vis[j] = false;
    }
    return ;
}

int cmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

char** permutation(char* s, int* returnSize){
    int len = strlen(s), recMaxSize = 1;
    for (int i = 2; i <= len; i++) {
        recMaxSize *= i;
    }
    char **rec = (char **)malloc(sizeof(char *) * recMaxSize);
    *returnSize = 0;
    int vis[len];
    memset(vis, 0, sizeof(vis));
    char temp[len + 1];
    temp[len] = '\0';
    qsort(s, len, sizeof(char), cmp);
    backtrack(rec, returnSize, vis, s, 0, len, temp);
    return rec;
}