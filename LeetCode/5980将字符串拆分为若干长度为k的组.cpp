/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** divideString(char * s, int k, char fill, int* returnSize){
    int len = strlen(s), t = 0, p;
    *returnSize = (len % k == 0) ? len / k : (len + k - len % k) / k;
    char **str = (char **)malloc(sizeof(char*) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++){
        str[i] = (char *)malloc(sizeof(char) * (k + 1));
        p = 0;
        for(int j = t; j < t + k; j++){
            if(j >= len) str[i][p++] = fill;
            else str[i][p++] = s[j]; 
        }
        str[i][p] = '\0';
        t = t + k;
    }
    return str;
}