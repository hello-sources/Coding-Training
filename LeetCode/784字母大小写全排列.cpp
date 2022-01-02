/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * s, int* returnSize){
    int len = strlen(s), ret = 1;
    char **res = (char **)malloc(sizeof(char *) * pow(2, len));
    *res = (char *)malloc((len + 5) * sizeof(char));
    strcpy(*res, s);
    for (int i = 0; i < len; i++) {
        if (s[i] > '9') {
            int k = ret;
            for (int j = 0; j < k; j++) {
                res[k + j] = (char *)malloc((len + 5) * sizeof(char));
                strcpy(res[k + j], res[j]);
                res[k + j][i] = s[i] < 'a' ? s[i] + 32 : s[i] - 32;
                ret++;
            }
        }
    }
    *returnSize = ret;
    return res;
}